extern "C" unsigned int func_0010FC30();

struct Obj_0026FC00 {
    char pad0[4];
    bool m_on;
    unsigned int m_onTime;
    unsigned int m_offTime;
    int m_value;
    bool m_onEvent;
    bool m_offEvent;
    char pad1C[4];
    float m_holdUntil;

    void Update(int value);
};

void Obj_0026FC00::Update(int value)
{
    if (m_holdUntil != 0.0f) {
        if (value <= 0x40)
            m_holdUntil = 0.0f;
        else if (m_holdUntil < (float)func_0010FC30())
            m_holdUntil = 0.0f;
        else
            return;
    }
    m_value = value;
    if (value > 0x40) {
        if (!m_on) {
            m_onTime = func_0010FC30();
            m_onEvent = true;
        }
        m_on = true;
    } else {
        if (m_on) {
            m_offTime = func_0010FC30();
            m_offEvent = true;
        }
        m_on = false;
    }
}
