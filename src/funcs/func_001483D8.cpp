extern unsigned char D_004653E8[];
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Pal_001483D8 {
    char pad[0x10];
    unsigned char* m_pixels;
    unsigned int* m_palette;
};

class B_001483D8 {
public:
    int m0;
    int m4;
    virtual void v0();
};

class C_001483D8 : public B_001483D8 {
public:
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Pal_001483D8* m1C;
    int m20;
    void* m24;
    unsigned int* m28;
    virtual void v0();
    void GetRect(unsigned int* out, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
};

void C_001483D8::GetRect(unsigned int* out, unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
    if (m28) {
        unsigned int* src = m28 + (y * m_w + x);
        for (unsigned int i = 0; i < h; i++) {
            func_00331404(out, src, w * 4);
            out += w;
            src += m_w;
        }
    } else {
        int top = y + 1;
        unsigned char* src = m1C->m_pixels;
        src += (m_h - top) * m_w + x;
        unsigned int* pal = m1C->m_palette;
        for (unsigned int j = 0; j < h; j++) {
            for (unsigned int k = 0; k < w; k++) {
                *out = pal[D_004653E8[src[k]]];
                out++;
            }
            src -= m_w;
        }
    }
}
