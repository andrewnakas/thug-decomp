struct Q_00184EB8 {
    float x, y, z, w;
    void Identity() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct M_00184EB8 {
    float m[4][4];
    void Identity()
    {
        m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f; m[0][3] = 0.0f;
        m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f; m[1][3] = 0.0f;
        m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = 1.0f; m[2][3] = 0.0f;
        m[3][0] = 0.0f; m[3][1] = 0.0f; m[3][2] = 0.0f; m[3][3] = 1.0f;
    }
};

struct B_00184EB8 {
    int m0;
    int m4;
    B_00184EB8();
    virtual void V0();
};

struct C_00184EB8 : B_00184EB8 {
    unsigned int m_flags;
    char pad10[0x50 - 0x10];
    Q_00184EB8 m50;
    char pad60[0x10];
    M_00184EB8 m70;
    Q_00184EB8 mB0;
    M_00184EB8 mC0;
    int m100;
    int m104;
    C_00184EB8();
    virtual void V0();
};

C_00184EB8::C_00184EB8()
{
    m104 = 0;
    mB0.Identity();
    m50.Identity();
    m70.Identity();
    mC0.Identity();
    m100 = 0;
    m104 = 0;
    m_flags |= 0x20;
}
