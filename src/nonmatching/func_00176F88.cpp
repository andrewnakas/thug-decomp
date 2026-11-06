/* fuzzy: 82.7 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00176F88 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

extern Vec_00176F88* D_0038BF74;

/* returns the colour of slot `id` (0x1D..0x21) scaled by 16, or (0, 0, 0, 1) */
extern "C" Vec_00176F88 func_00176F88(int id)
{
    Vec_00176F88 v;
    v.w = 1.0f;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    switch (id) {
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
        v.q = D_0038BF74[id - 0x1D].q;
        break;
    default:
        return v;
    }
    v.x *= 16.0f;
    v.y *= 16.0f;
    v.z *= 16.0f;
    v.w = 1.0f;
    return v;
}
