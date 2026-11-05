struct State_00137CF0 {
    char pad[0x38];
    float m38;
    float m3C[2];
};

extern State_00137CF0 D_003BEB00;

struct Fader_00137CF0 {
    float m_cur;
    float m_target;
    float m8;
    float mC[2];
    int m14;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    void Refresh();
};

void Fader_00137CF0::Refresh()
{
    m8 = (m_cur + m_cur - 1.0f) * D_003BEB00.m38 + 1.0f;
    if (m8 < 0.0f) {
        m8 = 0.0f;
    }
    for (int i = 0; i < 2; i++) {
        mC[i] = (m_cur + m_cur - 1.0f) * D_003BEB00.m3C[i] + 1.0f;
        if (mC[i] < 0.0f) {
            mC[i] = 0.0f;
        }
    }
    V8();
}
