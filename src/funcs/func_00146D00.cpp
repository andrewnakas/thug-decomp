extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00331404(void* dst, const void* src, int n);

class X_00146D00 {
public:
    char pad[0x58];
    X_00146D00(const X_00146D00* o);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

class B_00146D00 {
public:
    int m0;
    int m4;
    B_00146D00(const B_00146D00& o);
    virtual void v0();
};

class C_00146D00 : public B_00146D00 {
public:
    unsigned short m_w;
    unsigned short m_h;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    X_00146D00* m1C;
    int m20;
    void* m24;
    void* m28;
    X_00146D00* m2C;
    C_00146D00(const C_00146D00& o);
    virtual void v0();
};

C_00146D00::C_00146D00(const C_00146D00& o) : B_00146D00(o)
{
    m_w = o.m_w;
    m_h = o.m_h;
    m10 = o.m10;
    m11 = o.m11;
    m12 = o.m12;
    m14 = o.m14;
    m18 = o.m18;
    m20 = 0;
    if (o.m24) {
        m24 = func_0010A638(D_00388A70, m_w * m_h * 4, 1, 0);
        func_00331404(m24, o.m24, m_w * m_h * 4);
    } else {
        m24 = 0;
    }
    if (o.m28) {
        m28 = func_0010A638(D_00388A70, m_w * m_h * 4, 1, 0);
        func_00331404(m28, o.m28, m_w * m_h * 4);
    } else {
        m28 = 0;
    }
    if (o.m1C) {
        m1C = new X_00146D00(o.m1C);
    } else {
        m1C = 0;
    }
    if (o.m2C) {
        m2C = new X_00146D00(o.m2C);
    } else {
        m2C = 0;
    }
}
