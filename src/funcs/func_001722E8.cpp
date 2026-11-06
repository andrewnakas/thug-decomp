struct In_001722E8 {
    int m0[8];
    float m_20;
    float m_24;
};

struct Obj_001722E8 {
    int m0[13];
    In_001722E8* m_34;
    void Set(float a, float b);
};

void Obj_001722E8::Set(float a, float b)
{
    m_34->m_20 = a;
    m_34->m_24 = b;
}
