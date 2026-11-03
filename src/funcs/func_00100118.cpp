extern "C" float sqrtf(float);

float Acos(float x)
{
    if (x < 0.0f) {
        x = -x;
        float s = sqrtf(1.0f - x);
        return 3.14159265f - (((-0.0187293f * x + 0.0742610f) * x - 0.2121144f) * x + 1.5707288f) * s;
    }
    float s = sqrtf(1.0f - x);
    return (((-0.0187293f * x + 0.0742610f) * x - 0.2121144f) * x + 1.5707288f) * s;
}
