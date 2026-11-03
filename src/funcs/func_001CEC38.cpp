struct ObjComponent {
    int m0;
    unsigned int m_type;
    int m8;
    int m_pad[3];
    ObjComponent();
    virtual ~ObjComponent();
};

struct Comp_001CEC38 : ObjComponent {
    int m1C;
    int m20;
    int m24;
    int m28;
    char pad[0x9C - 0x2C];
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    Comp_001CEC38();
    virtual void Update();
    virtual ~Comp_001CEC38();
};

Comp_001CEC38::Comp_001CEC38()
{
    m_type = 0x28C97F3C;
    mB8 = 0;
    mBC = 0;
    m1C = 0;
    m20 = 0;
    m9C = 0;
    mA0 = 0;
    mA8 = 0;
    mAC = 0;
    mB0 = 0;
    mB4 = 0;
    m24 = 0;
    m28 = 0;
}
