extern "C" float fabsf(float);

struct Obj_001A86F8;
extern "C" void func_001A7750(Obj_001A86F8* o, int axis, float angle);

struct Obj_001A86F8 {
    char pad[0x20];
    unsigned int m20;
    char pad24[0x160 - 0x24];
    float m160[4];
    float m170[4];
    float m180[4];
    float m190[4];
    float m1A0[4];
    float m1B0[4];
    char pad1C0[0x210 - 0x1C0];
    float m210;
    int Method(int i);
};

int Obj_001A86F8::Method(int i)
{
    int reached = 0;
    if (m1A0[i] != 0.0f) {
        m190[i] += m1A0[i] * m210;
        float v = m190[i];
        float lim = m180[i];
        if (fabsf(lim) < fabsf(v)) {
            if ((v > 0.0f) == (lim > 0.0f))
                m190[i] = lim;
        }
    }
    if (m1B0[i] != 0.0f) {

        float step = m1B0[i] * m210;
        if (fabsf(m190[i] - m180[i]) < fabsf(step)) {
            m190[i] = m180[i];
            m1B0[i] = 0.0f;
            if (m180[i] == 0.0f)
                return 1;
            return 0;
        }
        m190[i] -= step;
    }
    float d = m190[i] * m210;
    if (!(m20 & (0x20 << i))) {
        int before = m160[i] > m170[i];
        m170[i] += d;
        if (before != (m160[i] > m170[i])) {
            reached = 1;
            d += m160[i] - m170[i];
        }
    }
    func_001A7750(this, i, d);
    return reached;
}
