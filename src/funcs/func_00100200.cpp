extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

extern "C" float* func_00100200(float* m, float x, float y, float z)
{
    float cx = func_00340F60(x);
    float sx = func_00341068(x);
    float cy = func_00340F60(y);
    float sy = func_00341068(y);
    float cz = func_00340F60(z);
    float sz = func_00341068(z);
    m[0] = cy * cz;
    m[1] = -cy * sz;
    m[2] = -sy;
    m[4] = -(sx * sy) * cz + cx * sz;
    m[5] = sx * sy * sz + cx * cz;
    m[6] = -sx * cy;
    m[8] = cx * sy * cz + sx * sz;
    m[9] = -(cx * sy) * sz + sx * cz;
    m[10] = cx * cy;
    m[3] = m[7] = m[11] = m[12] = m[13] = m[14] = 0.0f;
    m[15] = 1.0f;
    return m;
}
