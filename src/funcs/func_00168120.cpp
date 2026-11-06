struct Clock_00168120 {
    float m0;
    float m4;
    float m8;
    float mC;
};

extern Clock_00168120 D_003E1580;

static inline float Frame_00168120()
{
    return D_003E1580.mC * 16.0f;
}

struct Ch_00168120 {
    float m0;
    float m4;
    float m_val;
    float m_rate;
};

struct Obj_00168120 {
    char pad0[0x70];
    Ch_00168120 m70[4];
    void Fn(float t);
};

void Obj_00168120::Fn(float t)
{
    m70[0].m_val += m70[0].m_rate * t * Frame_00168120();
    m70[1].m_val += m70[1].m_rate * t * Frame_00168120();
    m70[2].m_val += m70[2].m_rate * t * Frame_00168120();
    m70[3].m_val += m70[3].m_rate * t * Frame_00168120();
}
