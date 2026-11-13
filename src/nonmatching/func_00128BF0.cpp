/* fuzzy: 88.6 */
#include "game/vector.h"

struct Vec_00128BF0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    Vec_00128BF0& operator+=(const Vec_00128BF0& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
};

struct Mat_00128BF0 {
    Vec_00128BF0 row[4];
    void Ident()
    {
        row[0].x = 1.0f; row[0].y = 0.0f; row[0].z = 0.0f; row[0].w = 0.0f;
        row[1].x = 0.0f; row[1].y = 1.0f; row[1].z = 0.0f; row[1].w = 0.0f;
        row[2].x = 0.0f; row[2].y = 0.0f; row[2].z = 1.0f; row[2].w = 0.0f;
        row[3].x = 0.0f; row[3].y = 0.0f; row[3].z = 0.0f; row[3].w = 1.0f;
    }
};

extern int D_00388814;
extern int D_0038882C;

extern "C" float func_0013B490();
extern "C" void* func_0013B0E8(void* self);
extern "C" Mat_00128BF0* func_00114E48(void* o);
extern "C" Vec_00128BF0* func_00114E18(void* o);
extern "C" Vec_00128BF0 func_00323298(Mat_00128BF0* m, Vec_00128BF0* v);
extern "C" void func_00323318(Mat_00128BF0* d, Mat_00128BF0* a, Mat_00128BF0* b);

static inline Vec_00128BF0 operator*(Mat_00128BF0& m, Vec_00128BF0& v)
{
    return func_00323298(&m, &v);
}

extern "C" void func_00128BF0(void* self, Mat_00128BF0* out, Vec_00128BF0* pos, float x, float y, float z)
{
    if (D_00388814 == 4)
        x = (int)(x * 0.9090909362f + 32.0f);
    else if (!D_0038882C)
        x *= 0.8000000119f;
    if (D_00388814 == 4)
        y += 16.0f;
    else if (!D_0038882C)
        y *= 1.142857194f;
    if (D_00388814 != 4) {
        if (!D_0038882C)
            x -= 256.0f;
        else
            x -= 320.0f;
    } else {
        x -= 306.0f;
    }
    if (D_00388814 != 4) {
        if (!D_0038882C)
            y -= 256.0f;
        else
            y -= 224.0f;
    } else {
        y -= 232.0f;
    }
    x = x * 0.7500000596f * func_0013B490();
    float t = -x * z;
    float sx;
    if (D_00388814 != 4) {
        if (!D_0038882C)
            sx = t * 0.002793296007f;
        else
            sx = t * 0.002232142957f;
    } else {
        sx = t * 0.002277904423f;
    }
    float u = y * z;
    float sy;
    if (D_00388814 != 4) {
        if (!D_0038882C)
            sy = u * 0.001953125f;
        else
            sy = u * 0.002232142957f;
    } else {
        sy = u * 0.002155172406f;
    }
    Vec_00128BF0 v;
    v.x = sx + pos->x;
    v.y = sy + pos->y;
    v.z = z + pos->z;
    v.w = pos->w + 1.0f;
    out->Ident();
    void* o = func_0013B0E8(self);
    if (!o)
        return;
    Mat_00128BF0 local;
    local = *func_00114E48(o);
    Vec_00128BF0* r = &local.row[3];
    r->Set(0.0f, 0.0f, 0.0f, 1.0f);
    Vec_00128BF0 w;
    w = local * v;
    Vec_00128BF0 q = *func_00114E18(o);
    q.w = 0.0f;
    w.x += q.x;
    w.y += q.y;
    w.z += q.z;
    w.w = q.w;
    func_00323318(out, &local, out);
    out->row[3] += w;
}
