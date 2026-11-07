/* fuzzy: 83.9 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00176F18 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00176F18() {}
    Vec_00176F18(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern Vec_00176F18* D_0038BF78;

Vec_00176F18 func_00176F18(int type)
{
    Vec_00176F18 r(1.0f, 1.0f, 1.0f, 1.0f);
    if ((unsigned)(type - 0x1D) < 5) {
        Vec_00176F18 t = D_0038BF78[type - 0x1D];
        r = t;
        r.y = t.z;
        r.z = t.y;
    }
    return r;
}
