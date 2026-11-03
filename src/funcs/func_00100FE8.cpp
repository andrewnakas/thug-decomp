#include "game/vector.h"

extern "C" float sqrtf(float);
extern "C" float func_003414F0(float, float);
extern "C" int func_003233B8(Vector* d, Vector* s);

struct Mat_00100FE8 {
    float m[4][4];
};

extern "C" void func_00100FE8(Mat_00100FE8* mat, Vector* axis, float* angle)
{
    Vector v;
    v.x = mat->m[1][2] - mat->m[2][1];
    v.y = mat->m[2][0] - mat->m[0][2];
    v.z = mat->m[0][1] - mat->m[1][0];
    v.w = 1.0f;
    float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    float t = mat->m[0][0] + mat->m[1][1] + mat->m[2][2] - 1.0f;
    if (len > 0.0f) {
        float inv = 1.0f / len;
        *axis = v;
        axis->x *= inv;
        axis->y *= inv;
        axis->z *= inv;
        axis->w *= inv;
    } else {
        axis->x = 0.0f;
        axis->y = 0.0f;
        axis->z = 0.0f;
        axis->w = 1.0f;
    }
    *angle = func_003414F0(len, t);
    if (len <= 0.01f && t <= 0.0f) {
        if (mat->m[0][0] > mat->m[1][1]) {
            if (mat->m[0][0] > mat->m[2][2]) {
                v.y = mat->m[0][1] + mat->m[1][0];
                v.z = mat->m[0][2] + mat->m[2][0];
                v.x = (mat->m[0][0] + 1.0f) * 2.0f;
            } else {
                v.x = mat->m[2][0] + mat->m[0][2];
                v.y = mat->m[2][1] + mat->m[1][2];
                v.z = (mat->m[2][2] + 1.0f) * 2.0f;
            }
        } else {
            if (mat->m[1][1] > mat->m[2][2]) {
                v.z = mat->m[1][2] + mat->m[2][1];
                v.x = mat->m[1][0] + mat->m[0][1];
                v.y = (mat->m[1][1] + 1.0f) * 2.0f;
            } else {
                v.x = mat->m[2][0] + mat->m[0][2];
                v.y = mat->m[2][1] + mat->m[1][2];
                v.z = (mat->m[2][2] + 1.0f) * 2.0f;
            }
        }
        *axis = v;
        func_003233B8(axis, axis);
    }
}
