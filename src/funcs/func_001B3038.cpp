extern "C" float func_00340F60(float x);

struct C_001B3038 {
    char pad[0x34];
    float m_weights[4];
    void Wave(float phase, float amp, float a, float b);
};

void C_001B3038::Wave(float phase, float amp, float a, float b)
{
    float k = amp * ((b - a) / b);
    float step = 1.5707965f;
    float lo = 1.57079637f;
    float hi = 4.712389f;
    for (int i = 0; i < 4; i++) {
        float* w = &m_weights[i];
        float x = step * (float)i - phase;
        float ax = __builtin_fabsf(x);
        if (lo <= ax && ax <= hi)
            continue;
        *w += k * func_00340F60(x);
        if (*w > 1.0f)
            *w = 1.0f;
        if (*w < -1.0f)
            *w = -1.0f;
    }
}
