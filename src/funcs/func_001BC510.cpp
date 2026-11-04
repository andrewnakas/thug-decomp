struct Base1BC510 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base1BC510();
    virtual ~Base1BC510();
};

struct Trip1BC510 {
    int a, b, c;
};

extern Trip1BC510 D_00363210;

struct Comp1BC510 : Base1BC510 {
    Trip1BC510 m1C;
    char m_pad28[0x5C - 0x28];
    int m5C;
    float m60;
    int m64;
    Comp1BC510();
    virtual void Update();
    virtual ~Comp1BC510();
};

Comp1BC510::Comp1BC510()
{
    m_type = 0xEADA1621;
    m1C = D_00363210;
    m5C = 2;
    m60 = 120.0f;
    m64 = 0;
}
