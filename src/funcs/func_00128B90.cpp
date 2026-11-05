extern "C" float func_00128B90(float a, float b, float c, float d, float e)
{
    float x = -((a * c) / ((a * 0.0007812500116f + 1.0f) * 640.0f) / d);
    float y = -((b * c) / ((a * 0.001116071478f + 1.0f) * 448.0f) / e);
    return x < y ? x : y;
}
