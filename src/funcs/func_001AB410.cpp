struct Base1AB410 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base1AB410();
    virtual ~Base1AB410();
};

struct Sub1AB410 {
    int m0;
    Sub1AB410();
};

struct Comp1AB410 : Base1AB410 {
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    char m_pad3C[0xA6C - 0x3C];
    int mA6C;
    char m_padA70[0x1404 - 0xA70];
    Sub1AB410 m1404;
    Comp1AB410();
    virtual void Update();
    virtual ~Comp1AB410();
};

extern "C" void func_001AB570(Comp1AB410* c);

Comp1AB410::Comp1AB410()
{
    mA6C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m2C = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m_type = 0x270F56E1;
    func_001AB570(this);
}
