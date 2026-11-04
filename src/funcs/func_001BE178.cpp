struct Base1BC510 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base1BC510();
    virtual ~Base1BC510();
};

struct Feeler_001A8940 {
    int m_data[56];
    Feeler_001A8940();
};

struct Elem1BE178 {
    int m_pad[12];
    Feeler_001A8940 m_feeler;
};

struct Quat1BE178 {
    float x, y, z, w;
    void Ident()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 1.0f;
    }
};

extern "C" void* func_001DAD40();

struct Comp1BE258 : Base1BC510 {
    int m1C[33];
    Quat1BE178 mA0;
    int mB0[8];
    Elem1BE178 m_elems[8];
    int m950[12];
    int m980;
    int m984[35];
    void* mA10;
    int mA14[5];
    int mA28[8];
    int mA48[10];
    Feeler_001A8940 mA70;
    int mB50[20];
    Quat1BE178 mBA0;
    Comp1BE258();
    virtual void Update();
    virtual ~Comp1BE258();
};

Comp1BE258::Comp1BE258()
{
    m_type = 0x726E85AA;
    mA10 = func_001DAD40();
    mA28[0] = 0;
    mA28[1] = 0;
    mA28[2] = 0;
    mA28[3] = 0;
    mA28[4] = 0;
    mA28[5] = 0;
    mA28[6] = 0;
    mA28[7] = 0;
    mA0.Ident();
    mBA0.Ident();
    m980 = 0;
}
