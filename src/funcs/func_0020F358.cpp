float func_0020F358(float a, float b, float t)
{
    float r = b + (a - b) * t;
    if (r < 0.0f)
        r = 0.0f;
    if (r > 255.0f)
        r = 255.0f;
    return r;
}
