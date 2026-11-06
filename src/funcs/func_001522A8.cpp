typedef int qword __attribute__((mode(TI)));

struct Vec_001522A8 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001522A8() {}
    Vec_001522A8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_001522A8 {
    Vec_001522A8 r[4];
};

Vec_001522A8 func_001522A8(const Mat_001522A8& m, const Vec_001522A8& v)
{
    Vec_001522A8 o(v.x * m.r[0].x + v.y * m.r[1].x + v.z * m.r[2].x,
                   v.x * m.r[0].y + v.y * m.r[1].y + v.z * m.r[2].y,
                   v.x * m.r[0].z + v.y * m.r[1].z + v.z * m.r[2].z,
                   v.w);
    return o;
}
