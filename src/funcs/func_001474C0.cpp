extern void* D_00388A70;
extern unsigned char D_004653E8[];
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00331404(void* dst, const void* src, int n);

struct Pal_001474C0 {
    char pad[0x10];
    unsigned char* m_pixels;
    unsigned int* m_palette;
};

class X_001474C0 {
public:
    char pad[0x58];
    X_001474C0(void* data, int w, int h, int bpp, int a, int b, int c, int d, int e);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class B_001474C0 {
public:
    int m0;
    int m4;
    virtual void v0();
};

class C_001474C0 : public B_001474C0 {
public:
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Pal_001474C0* m1C;
    int m20;
    void* m24;
    unsigned int* m28;
    X_001474C0* m2C;
    virtual void v0();
    bool Expand(bool makeTex, bool keepCopy);
};

bool C_001474C0::Expand(bool makeTex, bool keepCopy)
{
    m28 = (unsigned int*)func_0010A638(D_00388A70, m_w * m_h * 4, 1, 0);
    unsigned int* dst = m28;
    unsigned char* src = m1C->m_pixels;
    src += (m_h - 1) * m_w;
    unsigned int* pal = m1C->m_palette;
    for (unsigned int y = 0; y < m_h; y++) {
        for (unsigned int x = 0; x < m_w; x++) {
            *dst = pal[D_004653E8[src[x]]];
            dst++;
        }
        src -= m_w;
    }
    if (keepCopy) {
        m24 = func_0010A638(D_00388A70, m_w * m_h * 4, 1, 0);
        func_00331404(m24, m28, m_w * m_h * 4);
    }
    if (makeTex) {
        m2C = new X_001474C0(m28, m_w, m_h, 0x20, m11, m12, 1, 1, m18);
    }
    return true;
}
