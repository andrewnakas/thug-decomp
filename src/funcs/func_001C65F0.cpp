struct Obj_001C65F0 {
    char m_pad[0x1C];
    int m1C;
    unsigned int m20;
    char m_pad24[0x90 - 0x24];
    unsigned int m90;
    char m_pad94[0x954 - 0x94];
    float m954;
    float m958;
    void SetState(unsigned int state);
};

extern "C" unsigned int func_0010FC30();

void Obj_001C65F0::SetState(unsigned int state)
{
    if (m1C)
        return;
    unsigned int start = m20;
    if (func_0010FC30() - start < 100) {
        m958 = m954;
        return;
    }
    float cur = m954;
    float prev = m958;
    m958 = cur;
    m954 = cur < prev ? cur : prev;
    if (m90 != 0xAF895B3F)
        return;
    if (m954 != 0.0f)
        return;
    switch (state) {
    case 0x912220F8:
    case 0x1D537EFF:
    case 0xF28ADBFC:
        m90 = state;
        break;
    default:
        m90 = 0x9B46E749;
        break;
    }
}
