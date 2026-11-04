extern "C" float fabsf(float);

struct E_00198300 {
    int m0;
    int m4;
    int m8;
    char padC[0xB4 - 0xC];
    int mB4;
    char padB8[0x220 - 0xB8];
};

struct C_00198300 {
    char pad[0x1C4];
    int m_count;
    char pad1C8[0x318 - 0x1C8];
    E_00198300* m_items;
    char pad31C[0x34C - 0x31C];
    float m34C;
    int m350;
    int m354;
    int m358;
    void Update();
    void U0();
    void U1();
    void U2();
    void U3();
    void U4();
    void U5();
    void U6(float f);
    void U7();
    void U8();
};

void C_00198300::Update()
{
    U0();
    U1();
    U2();
    if (m358 == 0) {
        U3();
        U4();
        U5();
    } else if (m350 != 0) {
        U3();
        U6(1.0f - fabsf(m34C));
    } else {
        goto idle;
    }
    U7();
    U8();
    return;
idle:
    U7();
    int i = m_count;
        while (i--) {
            m_items[i].m8 = 0;
            m_items[i].mB4 = 0;
        }
}
