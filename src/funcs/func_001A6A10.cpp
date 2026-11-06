struct Obj_001A6A10 {
    char pad0[0x160];
    float m160[4];
    char pad170[0x180 - 0x170];
    float m180[4];
    float m190[4];
    float m1A0[4];
    float m1B0[4];
    void Fn(int i);
};

void Obj_001A6A10::Fn(int i)
{
    m190[i] = __builtin_fabsf(m190[i]);
    m180[i] = __builtin_fabsf(m180[i]);
    m1A0[i] = __builtin_fabsf(m1A0[i]);
    m1B0[i] = __builtin_fabsf(m1B0[i]);
    if (m160[i] < 0.0f) {
        m190[i] = -m190[i];
        m180[i] = -m180[i];
        m1A0[i] = -m1A0[i];
        m1B0[i] = -m1B0[i];
    }
}
