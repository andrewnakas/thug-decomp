/* fuzzy: 82.9 */
struct Obj_001A7A78 {
    char pad0[0x1C];
    int m1C;
    int m20;
    char pad24[0x28 - 0x24];
    float m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    char pad3C[0x1D0 - 0x3C];
    float m1D0;
    float m1D4;
    float m1D8;
    char pad1DC[0x210 - 0x1DC];
    float m210;
    void Fn();
};

void Obj_001A7A78::Fn()
{
    if (!(m1C & 0x10))
        return;
    if (m20 & 8) {
        if (m1D0 >= m38)
            return;
        m1D0 += m34 * m210;
        if (m38 == 0.0f || m38 <= m1D0) {
            m34 = 0.0f;
        } else {
            float r = m1D0 / m38;
            m34 = m1D4 * (1.0f - r) + m1D8 * r;
        }
    } else if (m34 < m30) {
        if (m28 == 0.0f) {
            m34 = m30;
            return;
        }
        float n = m34 + m28 * m210;
        m34 = n;
        if (n > m30)
            m34 = m30;
    } else if (m34 > m30) {
        if (m2C == 0.0f) {
            m34 = m30;
            return;
        }
        float n = m34 - m2C * m210;
        m34 = n;
        if (n < m30)
            m34 = m30;
    }
}
