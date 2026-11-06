struct Vec_00150E78 {
    float x, y, z, w;
    Vec_00150E78() {}
    Vec_00150E78(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float LengthSq() const { return x * x + y * y + z * z; }
};

static inline Vec_00150E78 Sub_00150E78(const Vec_00150E78& a, const Vec_00150E78& b)
{
    return Vec_00150E78(a.x - b.x, a.y - b.y, a.z - b.z, 0.0f);
}

static inline Vec_00150E78 Cross_00150E78(const Vec_00150E78& a, const Vec_00150E78& b)
{
    return Vec_00150E78(a.y * b.z - b.y * a.z, a.z * b.x - b.z * a.x, a.x * b.y - b.x * a.y, 0.0f);
}

int func_00150E78(const Vec_00150E78& a, const Vec_00150E78& b, const Vec_00150E78& c, float thresh)
{
    Vec_00150E78 e1 = Sub_00150E78(b, a);
    Vec_00150E78 e2 = Sub_00150E78(c, a);
    Vec_00150E78 n = Cross_00150E78(e1, e2);
    float l = n.LengthSq();
    int r = 0;
    if (l > thresh) {
        r = 1;
        while (l > thresh) {
            l *= 0.0625f;
            r <<= 2;
        }
        r--;
    }
    return r;
}
