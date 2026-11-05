extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);

extern "C" float* func_00100928(float* m, float angle)
{
    float s = func_00341068(angle);
    float c = func_00340F60(angle);
    m[0] = c; m[1] = 0.0f; m[2] = -s; m[3] = 0.0f;
    m[4] = 0.0f; m[5] = 1.0f; m[6] = 0.0f; m[7] = 0.0f;
    m[8] = s; m[9] = 0.0f; m[10] = c; m[11] = 0.0f;
    m[12] = 0.0f; m[13] = 0.0f; m[14] = 0.0f; m[15] = 1.0f;
    return m;
}
