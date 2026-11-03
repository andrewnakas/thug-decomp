extern "C" int func_00100030(int n);

float RndSigned(float range)
{
    return range * ((float)func_00100030(10000) - 5000.0f) * 0.0002f;
}
