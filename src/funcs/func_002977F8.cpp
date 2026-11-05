struct Vec_002977F8 {
    float x, y, z, w;
    Vec_002977F8() {}
    Vec_002977F8(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);

static inline Vec_002977F8 operator-(const Vec_002977F8& a, const Vec_002977F8& b)
{
    return Vec_002977F8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_002977F8 operator+(const Vec_002977F8& a, const Vec_002977F8& b)
{
    return Vec_002977F8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vec_002977F8 RotateAbout_002977F8(const Vec_002977F8& p, const Vec_002977F8& center, const Vec_002977F8& base, float deg)
{
    Vec_002977F8 d = p - center;
    float a = deg * 0.01745329425f;
    float s = func_00341068(a);
    float c = func_00340F60(a);
    Vec_002977F8 r;
    r.x = c * d.x + s * d.z;
    r.y = d.y;
    r.z = c * d.z - s * d.x;
    return base + r;
}
