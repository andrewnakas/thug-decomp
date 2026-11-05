struct Obj_0023ACE0 {
    char pad[0xB6C];
    char m_B6C[0x9C4];
    int m_1530;
    int m_1534;
    int m_1538;
    int m_153C;
    int m_1540;
    float m_1544;
    void Clear();
};

void Obj_0023ACE0::Clear()
{
    m_1534 = 0;
    m_1540 = 0;
    m_153C = 0;
    for (int i = 0; i < 0x9C4; i++) {
        m_B6C[i] = 0;
    }
    m_1544 = 1.0f;
}
