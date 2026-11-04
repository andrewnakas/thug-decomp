struct Base1A2EF0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base1A2EF0();
    virtual ~Base1A2EF0();
};

struct Vec1A2EF0 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Comp1A2EF0 : Base1A2EF0 {
    char m_pad1C[0xA0 - 0x1C];
    Vec1A2EF0 mA0;
    Vec1A2EF0 mB0;
    void* mC0;
    void* mC4;
    Comp1A2EF0();
    virtual void Update();
    virtual ~Comp1A2EF0();
};

Comp1A2EF0::Comp1A2EF0()
{
    m_type = 0x07713C7B;
    mC0 = 0;
    mC4 = 0;
    mA0.Set(0.0f, 0.0f, 0.0f, 1.0f);
    mB0.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
