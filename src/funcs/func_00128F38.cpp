struct V_00128F38 {
    float x, y, z, w;
    void Set(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }
};

struct M_00128F38 {
    V_00128F38 r[4];
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
};

struct E_00128F38 {
    int m0;
    int m4;
    int m8;
    int mC;
    V_00128F38 m10;
    E_00128F38() {}
};

struct B_00123628 {
    int m0;
    int m4;
    B_00123628();
    virtual void V0();
};

struct C_00128F38 : B_00123628 {
    char padC[0x1A0 - 0xC];
    E_00128F38 m_elems[25];
    int m4C0;
    float m4C4;
    int m4C8;
    int m4CC;
    int m4D0;
    int m4D4;
    int m4D8;
    int m4DC;
    M_00128F38 m4E0;
    V_00128F38 m520;
    int m530;
    int m534;
    int m538;
    char pad53C[0x550 - 0x53C];
    V_00128F38 m550;
    char pad560[0x570 - 0x560];
    V_00128F38 m570;
    float m580;
    int m584;
    float m588;
    float m58C;
    int m590;
    int m594;
    int m598;
    char pad59C[0x5A0 - 0x59C];
    int m5A0;
    int m5A4;
    C_00128F38();
    virtual void V0();
};

extern "C" void func_00183F08(C_00128F38* o, unsigned int id);

C_00128F38::C_00128F38()
{
    for (int i = 0; i < 25; i++) {
        E_00128F38* e = &m_elems[i];
        e->m0 = 0;
        e->m4 = 0;
        e->m10.Set(0.0f, 0.0f, 0.0f, 1.0f);
    }
    m4C0 = 0;
    m4C4 = -400.0f;
    m4C8 = 0;
    m4CC = 0;
    m4D0 = 0;
    m4D4 = 0;
    m4D8 = 0;
    m4DC = 0;
    m530 = 0;
    m534 = 2;
    m520.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m580 = 1.0f;
    m588 = 0.002f;
    m58C = 3.0f;
    m538 = 0;
    m5A0 = 0;
    m594 = 0;
    m598 = 0;
    m590 = 0;
    m584 = 0;
    m5A4 = 0;
    m4E0.Ident();
    m550.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m570.Set(0.0f, 0.0f, 0.0f, 1.0f);
    func_00183F08(this, 0x82C59D78);
}
