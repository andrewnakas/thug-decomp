struct Component {
    int m0;
    unsigned int m_type;
    int m8;
    int mC;
    int m10;
    int m14;
    Component();
    virtual ~Component();
};

struct Quat_0029CBC0 {
    float x, y, z, w;
    void Identity() { x = 0.0f; y = 0.0f; z = 0.0f; w = 1.0f; }
};

struct Comp_0029CBC0 : public Component {
    char pad1C[0x20 - 0x1C];
    Quat_0029CBC0 q0, q1, q2, q3, q4;
    int m70, m74, m78, m7C, m80, m84, m88, m8C, m90, m94, m98, m9C, mA0;
    Comp_0029CBC0();
    virtual void Update();
    virtual ~Comp_0029CBC0();
};

Comp_0029CBC0::Comp_0029CBC0()
{
    m_type = 0xAC8946E2;
    q0.Identity();
    q1.Identity();
    q2.Identity();
    q3.Identity();
    q4.Identity();
    m70 = 0;
    m74 = 0;
    m78 = 0;
    m7C = 0;
    m80 = 0;
    m84 = 0;
    m88 = 0;
    m8C = 0;
    m90 = 0;
    mA0 = 0;
    m9C = 0;
    m94 = 0;
    m98 = 0;
}
