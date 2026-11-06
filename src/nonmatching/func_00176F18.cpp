/* fuzzy: 61.3 */
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
    int i;
    switch (type) {
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
        i = type - 0x1D;
        break;
    default:
        i = -1;
        break;
    }
    if (i != -1) {
        Vec_00176F18 t = D_0038BF78[i];
        r = t;
        r.y = t.z;
        r.z = t.y;
    }
    return r;
}
