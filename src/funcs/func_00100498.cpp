extern "C" float func_003413F0(float a);
extern "C" float func_00340F60(float a);
extern "C" float func_00100348(float y, float x);

extern "C" void func_00100498(const float* m, float* out)
{
    float s = m[2];
    if (s > 1.0f) s = 1.0f;
    if (s < -1.0f) s = -1.0f;
    out[1] = -func_003413F0(s);
    float c = func_00340F60(out[1]);
    if (__builtin_fabsf(c) > 0.005f) {
        out[0] = func_00100348(-m[6] / c, m[10] / c);
        out[2] = func_00100348(-m[1] / c, m[0] / c);
    } else {
        out[0] = 0.0f;
        out[2] = func_00100348(m[4], m[5]);
    }
}
