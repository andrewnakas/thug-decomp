struct Vec_00298160 {
    float x, y, z, w;
    Vec_00298160() {}
    Vec_00298160(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

extern "C" void func_003233B8(Vec_00298160* d, Vec_00298160* s);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" float func_00340F60(float);

static inline Vec_00298160 operator-(const Vec_00298160& a, const Vec_00298160& b)
{
    return Vec_00298160(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

bool Check_00298160(const Vec_00298160& a, const Vec_00298160& b, const Vec_00298160& c)
{
    Vec_00298160 d1 = b - a;
    d1.y = 0.0f;
    func_003233B8(&d1, &d1);
    Vec_00298160 d2 = c - b;
    d2.y = 0.0f;
    func_003233B8(&d2, &d2);
    float dot = d1.x * d2.x + d1.y * d2.y + d1.z * d2.z;
    if (dot < func_00340F60(func_001E5318(0x76C1DA15, 0) * 0.01745329425f))
        return false;
    return true;
}
