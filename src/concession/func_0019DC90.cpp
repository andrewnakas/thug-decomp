/* force: {"kind": "fr", "reg": 120, "hard": 33} */
float func_0019DC90(float a, float step)
{
    float half = step * 0.5f;
    float t = half + -3.141593f;
    float lim = 3.141593f;
    while (t < lim) {
        if (a < t)
            return t - half;
        t += step;
    }
    return t - half;
}
