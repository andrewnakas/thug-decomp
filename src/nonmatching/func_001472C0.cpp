/* fuzzy: 75.6 */
extern "C" void* func_00331404(void* dst, const void* src, int n);
struct C_00181C00;
extern "C" int func_00181BC0(C_00181C00* self);
extern "C" void func_00181C00(C_00181C00* self, char* src);

struct C_00181C00 {
    char pad0[0x28];
    char* m_pixels;
    char pad2C[4];
    char* m_clut;
};

struct Src_001472C0 {
    char pad0[0x10];
    char* m_pixels;
    unsigned short* m_clut;
    unsigned int m_size;
    unsigned int m_clutSize;
};

struct Col_001472C0 {
    unsigned char r, g, b, a;
};

struct Tex_001472C0 {
    char pad0[0xC];
    int m_C;
    union {
        unsigned int m_10;
        struct {
            unsigned char m_fmt;
            unsigned char m_bits;
            unsigned char m_12;
            unsigned char m_13;
        };
    };
    char pad14[0x1C - 0x14];
    Src_001472C0* m_src;
    C_00181C00* m_dst;
    int GetBits() { return m_bits; }
    bool Copy(Tex_001472C0* o);
};

static inline bool ConvertClut_001472C0(void* dclut, unsigned char dbits, Src_001472C0* src, unsigned char sbits)
{
    unsigned short* sclut = src->m_clut;
    if (dbits == sbits) {
        func_00331404(dclut, sclut, src->m_clutSize);
        return true;
    }
    if (dbits == 0x20 && sbits == 0x10) {
        Col_001472C0 c;
        c.a = 0x80;
        int n = src->m_clutSize >> 1;
        unsigned int* d = (unsigned int*)dclut;
        for (int i = 0; i < n; i++) {
            c.r = *sclut << 3;
            c.g = (*sclut >> 2) & 0xF8;
            c.b = (*sclut >> 7) & 0xF8;
            sclut++;
            *d++ = *(unsigned int*)&c;
        }
        return true;
    }
    if (dbits == 0x10 && sbits == 0x20) {
        int n = src->m_clutSize >> 2;
        unsigned short* d = (unsigned short*)dclut;
        unsigned char* p = (unsigned char*)sclut;
        for (int i = 0; i < n; i++) {
            unsigned char* q = p;
            p += 4;
            *d++ = (q[0] >> 3) | 0x8000 | ((q[1] >> 3) << 5) | ((q[2] >> 3) << 10);
        }
        return true;
    }
    return false;
}

bool Tex_001472C0::Copy(Tex_001472C0* o)
{
    if (m_C != o->m_C) return false;
    if ((m_10 & 0xFF00FF) != (o->m_10 & 0xFF00FF)) return false;
    char* dpix = m_dst->m_pixels;
    char* spix = o->m_src->m_pixels;
    if (func_00181BC0(m_dst)) {
        func_00181C00(m_dst, spix);
    } else {
        func_00331404(dpix, spix, o->m_src->m_size);
    }
    char* dclut = m_dst->m_clut;
    if (!dclut) return true;
    return ConvertClut_001472C0(dclut, GetBits(), o->m_src, o->GetBits());
}
