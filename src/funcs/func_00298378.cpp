extern "C" float sqrtf(float);
extern "C" float fabsf(float);

struct Vec_00298378 {
    float x, y, z, w;
    void Sub(const Vec_00298378& a, const Vec_00298378& b)
    {
        x = a.x - b.x;
        y = a.y - b.y;
        z = a.z - b.z;
        w = a.w - b.w;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

extern "C" bool func_00298278(const Vec_00298378* a, const Vec_00298378* b);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" void func_003233B8(Vec_00298378* out, Vec_00298378* in);
extern "C" float func_00341068(float);

extern "C" bool func_00298378(const Vec_00298378* a, const Vec_00298378* b)
{
    if (func_00298278(a, b))
        return false;
    Vec_00298378 d;
    d.Sub(*a, *b);
    float len = d.Length();
    if (len < func_001E5318(0x8BEA1C03, 0))
        return false;
    func_003233B8(&d, &d);
    float y = fabsf(d.y);
    if (y > func_00341068(func_001E5318(0x9FD761AF, 0) * 0.01745329425f))
        return false;
    return true;
}
