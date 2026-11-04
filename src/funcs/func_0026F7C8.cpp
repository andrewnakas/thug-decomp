extern "C" float fabsf(float);
extern "C" float sqrtf(float);
extern "C" float func_00340F60(float);

float func_0026F7C8(float a, float b, float c)
{
    float x = a * (a > 0.0f ? 0.007874015719f : 0.0078125f);
    float y = b * (b > 0.0f ? 0.007874015719f : 0.0078125f);
    float ang;
    if (c > -0.7853981853f && c < 0.7853981853f)
        ang = c;
    else if (c > 0.7853981853f && c < 2.356194496f)
        ang = c - 1.570796371f;
    else if (fabsf(c) > 2.356194496f)
        ang = fabsf(c) - 3.141592741f;
    else
        ang = c + 1.570796371f;
    return sqrtf(x * x + y * y) * fabsf(func_00340F60(ang));
}
