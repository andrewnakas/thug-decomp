extern "C" float sqrtf(float);

struct Vec_00298278 {
    float x, y, z, w;
    void Sub(const Vec_00298278& a, const Vec_00298278& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

extern "C" bool func_00298278(const Vec_00298278* a, const Vec_00298278* b)
{
    Vec_00298278 d;
    d.Sub(*a, *b);
    return d.Length() > 4000.0f;
}
