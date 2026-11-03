extern "C" float func_001E5318(unsigned int name, int flags);

struct Base184DD8 {
    int m_pad[6];
    Base184DD8();
    virtual ~Base184DD8();
};

struct Vec1B10D0 {
    float x, y, z, w;
    Vec1B10D0() {}
};

struct Comp1B10D0 : Base184DD8 {
    int m1C;
    int m20;
    int m24[4];
    int m34[4];
    int m44[15];
    int m80;
    int m84;
    int m88;
    int m8C[14];
    float mC4;
    float mC8;
    int mCC;
    int mD0[4];
    Vec1B10D0 m_vecs[5];
    Comp1B10D0();
    virtual void Update();
    virtual ~Comp1B10D0();
};

extern "C" void func_001B3508(Comp1B10D0* self);

Comp1B10D0::Comp1B10D0()
{
    m_pad[1] = 0x6EFDDFB8;
    for (int i = 3; i >= 0; i--) m34[i] = 0;
    func_001B3508(this);
    m80 = 0;
    m84 = 0;
    m88 = 0;
    mC4 = func_001E5318(0x379D93D2, 1);
    mC8 = func_001E5318(0x8715B7B2, 1);
    m20 = 0;
    mCC = 0;
}
