struct Vec_0014F148 {
    float x, y, z, w;
    Vec_0014F148() {}
    Vec_0014F148(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

static inline Vec_0014F148 operator-(const Vec_0014F148& a, const Vec_0014F148& b)
{
    return Vec_0014F148(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_0014F148 Cross(const Vec_0014F148& a, const Vec_0014F148& b)
{
    return Vec_0014F148(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Dot(const Vec_0014F148& a, const Vec_0014F148& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

bool func_0014F148(const Vec_0014F148& p, const Vec_0014F148& a, const Vec_0014F148& o, const Vec_0014F148& b)
{
    Vec_0014F148 c1 = Cross(b - o, p - o);
    Vec_0014F148 c2 = Cross(b - o, a - o);
    return Dot(c1, c2) >= 0.0f;
}
