extern unsigned char D_004654E8[];
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Rgba_00148250 {
    unsigned char r, g, b, a;
};

struct Pal_00148250 {
    char pad[0x10];
    unsigned char* m_pixels;
    unsigned int* m_palette;
};

class B_00148250 {
public:
    int m0;
    int m4;
    virtual void v0();
};

class C_00148250 : public B_00148250 {
public:
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Pal_00148250* m1C;
    int m20;
    void* m24;
    Rgba_00148250* m28;
    virtual void v0();
    int Search(Rgba_00148250* c);
    void SetRect(Rgba_00148250* in, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
};

void C_00148250::SetRect(Rgba_00148250* in, unsigned short x, unsigned short y, unsigned short w, unsigned short h)
{
    if (m28) {
        Rgba_00148250* dst = m28 + (y * m_w + x);
        for (unsigned int i = 0; i < h; i++) {
            func_00331404(dst, in, w * 4);
            in += w;
            dst += m_w;
        }
    } else {
        int top = y + 1;
        unsigned char* dst = m1C->m_pixels;
        dst += (m_h - top) * m_w + x;
        for (unsigned int j = 0; j < h; j++) {
            for (unsigned int k = 0; k < w; k++) {
                Rgba_00148250 c = *in;
                in++;
                dst[k] = D_004654E8[Search(&c)];
            }
            dst -= m_w;
        }
    }
}
