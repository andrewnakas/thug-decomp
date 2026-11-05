extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);

extern "C" float* func_001009C0(float* m, float angle)
{
    float s = func_00341068(angle);
    float c = func_00340F60(angle);
    m[0] = c; m[1] = s; m[2] = 0.0f; m[3] = 0.0f;
    m[4] = -s; m[5] = c; m[6] = 0.0f; m[7] = 0.0f;
    m[8] = 0.0f; m[9] = 0.0f; m[10] = 1.0f; m[11] = 0.0f;
    m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
    return m;
}
