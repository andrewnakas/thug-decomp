/* fuzzy: 91.5 */
/* sym: Begin__10C_00147650ii = 0x00147FB0 */
/* sym: Lookup__10C_00147650P13Rgba_00147650 = 0x00148250 */
/* sym: End__10C_00147650 = 0x001483B0 */
/* sym: _$_10X_00147650 = 0x0017E0B0 */
extern void* D_00388A70;
extern unsigned char D_004654E8[];
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void func_00160D18(unsigned int* pal, void* data, int w, int h, int bpp, int colors);

struct Rgba_00147650 {
    unsigned char r, g, b, a;
};

struct Pal_00147650 {
    char pad[0x10];
    unsigned char* m_pixels;
    unsigned int* m_palette;
};

class X_00147650 {
public:
    char pad[0x58];
    ~X_00147650();
};

class B_00147650 {
public:
    int m0;
    int m4;
    virtual void v0();
};

class C_00147650 : public B_00147650 {
public:
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m_bits;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Pal_00147650* m1C;
    int m20;
    void* m24;
    Rgba_00147650* m28;
    X_00147650* m2C;
    virtual void v0();
    void Begin(int a, int w);
    int Lookup(Rgba_00147650* c);
    void End();
    bool Quantize(bool buildPalette);
};

bool C_00147650::Quantize(bool buildPalette)
{
    if (buildPalette) {
        func_00160D18(m1C->m_palette, m28, m_w, m_h, 0x20, 1 << m_bits);
    }
    {
        unsigned char* dst = m1C->m_pixels;
        dst += (m_h - 1) * m_w;
        Rgba_00147650* src = m28;
        Begin(0, m_w);
        for (unsigned int y = 0; y < m_h; y++) {
            for (unsigned int x = 0; x < m_w; x++) {
                Rgba_00147650 c = *src;
                dst[x] = D_004654E8[Lookup(&c)];
                src++;
            }
            dst -= m_w;
        }
        End();
    }
    if (m28) {
        func_0010A8D8(D_00388A70, m28);
    }
    m28 = 0;
    if (m24) {
        func_0010A8D8(D_00388A70, m24);
        m24 = 0;
    }
    if (m2C) {
        delete m2C;
        m2C = 0;
    }
    return true;
}
