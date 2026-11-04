extern "C" float func_00340F60(float x);

struct C_001B3138 {
    char pad[0x24];
    float m_base[4];
    void Wave(float phase, float amp);
};

void C_001B3138::Wave(float phase, float amp)
{
    float step = 1.5707965f;
    float lo = 1.57079637f;
    float hi = 4.712389f;
    for (int i = 0; i < 4; i++) {
        float* w = &m_base[i];
        float x = step * (float)i - phase;
        float ax = __builtin_fabsf(x);
        if (lo <= ax && ax <= hi)
            continue;
        *w += amp * func_00340F60(x);
        if (*w > 1.0f)
            *w = 1.0f;
        if (*w < -1.0f)
            *w = -1.0f;
    }
}
