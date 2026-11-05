struct Obj_00119770 {
    int m0[6];
    float m_18;
    float m_1C;
    float m_20;
    int m24;
    int m_28;
    void Get(float* x, float* y, float* z);
};

void Obj_00119770::Get(float* x, float* y, float* z)
{
    *y = m_1C;
    if (!m_28) {
        *x = m_18;
        *z = m_20;
    } else {
        *x = m_20;
        *z = m_18;
    }
}
