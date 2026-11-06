/* fuzzy: 83.6 */
struct Vec_001BA4F0 {
    float x, y, z, w;
};

extern "C" float sqrtf(float);
extern "C" float func_00341068(float x);
extern "C" float func_00340F60(float x);

struct Quat_001BA4F0;
extern "C" void func_00119230(Quat_001BA4F0* q, float x, float y, float z);
extern "C" void func_00119228(Quat_001BA4F0* q, float w);

struct Quat_001BA4F0 {
    float x, y, z, w;
    Quat_001BA4F0* SetAxisAngle(const Vec_001BA4F0* axis, float angle);
};

Quat_001BA4F0* Quat_001BA4F0::SetAxisAngle(const Vec_001BA4F0* axis, float angle)
{
    float half = angle * 0.5f;
    float len = sqrtf(axis->x * axis->x + axis->y * axis->y + axis->z * axis->z);
    float inv;
    if (len > 0.0f)
        inv = 1.0f / len;
    else
        inv = 0.0f;
    float s = inv * func_00341068(half);
    func_00119230(this, s * axis->x, s * axis->y, s * axis->z);
    func_00119228(this, func_00340F60(half));
    return this;
}
