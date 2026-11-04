extern void* D_0038C0F8;
extern "C" int func_00165AC8(int v);
extern "C" int func_0017EE98(int fmt);

struct C_0017DE70 {
    int m0;
    int m_flags;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
    char pad28[0x38 - 0x28];
    int m38;
    int m3C;
    unsigned short m_width;
    unsigned short m_height;
    int m44;
    int m48;
    void* m_next;
    int m50;
    C_0017DE70* Init(void* data, int width, int height, int fmt, int clutFmt, int levels, int linked, int a8, int flip);
    void Setup(void* data, int w, int h, int fmt, int clutFmt, int levels, int z);
    void FlipV();
};

C_0017DE70* C_0017DE70::Init(void* data, int width, int height, int fmt, int clutFmt, int levels, int linked, int a8, int flip)
{
    m_flags = 0;
    m50 = 0;
    m3C = 0;
    m38 = 0;
    if (flip) m_flags = 1;
    if (linked) {
        m_flags |= 8;
        if (a8 && !flip) m_flags |= 2;
    }
    m_height = height;
    m14 = 0;
    m10 = 0;
    m1C = 0;
    m18 = 0;
    mC = 0;
    m24 = 0;
    m0 = 0;
    m_width = width;
    int w = func_00165AC8(width - 1);
    int h = func_00165AC8(height - 1);
    int f = func_0017EE98(fmt);
    int cf = func_0017EE98(clutFmt);
    m_flags |= 0x10;
    Setup(data, w, h, f, cf, levels - 1, 0);
    if (linked && !flip) {
        m_next = D_0038C0F8;
        D_0038C0F8 = this;
    }
    if (flip) FlipV();
    return this;
}
