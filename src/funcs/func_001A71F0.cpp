extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);

struct Vec_001A71F0 {
    float x, y, z, w;
    float& operator[](int i) { return (&x)[i]; }
};

struct C_001A71F0 {
    int m_pad[7];
    int m1C;
    int m20;
    int m_pad2[79];
    Vec_001A71F0 m160;
    Vec_001A71F0 m170;
    Vec_001A71F0 m180;
    Vec_001A71F0 m190;
    Vec_001A71F0 m1A0;
    Vec_001A71F0 m1B0;
    void Setup(void* params, int unused, int axis);
};

extern "C" void func_001A6A10(C_001A71F0* self, int axis);

void C_001A71F0::Setup(void* params, int unused, int axis)
{
    float sign = 1.0f;
    if (m1C & 0x40) {
        m1C &= ~0x40;
        m1C &= ~7;
    }
    if (func_001E8708(params, 0x26AF9DC9)) {
        switch (axis) {
        case 0: sign = -1.0f; break;
        case 1: axis = 2; break;
        case 2: axis = 1; break;
        }
    }
    m1B0[axis] = 0.0f;
    m1A0[axis] = 0.0f;
    m160[axis] = 0.0f;
    if (func_001E7EB0(params, 0xFF7EBAF6, &m160[axis], 0)) {
        m160[axis] = sign * (m160[axis] * 0.0174532942f);
        m20 &= ~(0x20 << axis);
        m170[axis] = 0.0f;
        m190[axis] = 0.0f;
        if (m160[axis] == m190[axis]) {
            m1C &= ~(1 << axis);
            return;
        }
    }
    if (func_001E7EB0(params, 0xF59FF7D7, &m1B0[axis], 0)) {
        m1B0[axis] *= 0.0174532942f;
        if (func_001E7EB0(params, 0xF0D90109, &m180[axis], 0)) m180[axis] *= 0.0174532942f;
    } else if (func_001E7EB0(params, 0x85894A84, &m1A0[axis], 0)) {
        m1A0[axis] *= 0.0174532942f;
        if (func_001E7EB0(params, 0xF0D90109, &m180[axis], 0)) m180[axis] *= 0.0174532942f;
        if (!((m1C >> axis) & 1)) m190[axis] = 0.0f;
    } else {
        if (func_001E7EB0(params, 0xF0D90109, &m190[axis], 0)) m190[axis] *= 0.0174532942f;
    }
    if (m160[axis] == 0.0f && m1B0[axis] == 0.0f) m20 |= 0x20 << axis;
    if (!(m20 & (0x20 << axis))) func_001A6A10(this, axis);
    m1C |= 1 << axis;
}
