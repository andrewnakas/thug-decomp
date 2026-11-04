extern "C" float func_00341068(float x);
extern "C" float func_001E5318(unsigned int name, int flag);

struct C_001B32B8 {
    char pad[0x24];
    float m_base[4];
    float m_weights[4];
    float Balance();
};

float C_001B32B8::Balance()
{
    float sum = 0.0f;
    float step = 1.5707965f;
    float* p = m_base;
    for (int i = 0; i < 4; i++, p++) {
        float a = step * (float)i;
        float w = p[4] + p[0];
        if (w > 1.0f)
            w = 1.0f;
        sum += -func_00341068(a) * w;
        if (sum >= 1.0f)
            return 1.0f;
        if (sum <= -1.0f)
            return -1.0f;
    }
    if (__builtin_fabsf(sum) < func_001E5318(0x4ABA9798, 1))
        sum = 0.0f;
    return sum;
}
