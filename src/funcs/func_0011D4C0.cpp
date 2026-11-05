struct Vec_0011D4C0 {
    float x, y, z, w;
    float LengthSq4();
};

float Vec_0011D4C0::LengthSq4()
{
    return x * x + y * y + z * z + w * w;
}
