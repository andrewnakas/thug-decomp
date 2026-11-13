/* fuzzy: 99.0 */
extern "C" float sqrtf(float);
extern "C" float fabsf(float);

struct Vec_001DE8F0 {
    float x, y, z, w;
    Vec_001DE8F0() {}
    Vec_001DE8F0(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline float Dist_001DE8F0(const Vec_001DE8F0& a, const Vec_001DE8F0& b)
{
    Vec_001DE8F0 d(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    return sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
}

extern "C" float func_0010FAB8();

struct Obj_001DE8F0 {
    char pad[0x50];
    Vec_001DE8F0 m_pos;
    float DistTo(const Vec_001DE8F0& b) const
    {
        Vec_001DE8F0 d(m_pos.x - b.x, m_pos.y - b.y, m_pos.z - b.z, m_pos.w - b.w);
        return sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    }
};

static inline float Frames_001DE8F0()
{
    return func_0010FAB8() * 60.0f;
}

extern "C" bool func_001DC418();
extern "C" Obj_001DE8F0* func_0013B108(Vec_001DE8F0*, int);
extern "C" Vec_001DE8F0* func_00114E18(Obj_001DE8F0*);

void func_001DE8F0(void* ctx, float* out, Vec_001DE8F0* target, Vec_001DE8F0* pos, Obj_001DE8F0* obj, float scale)
{
    if (func_001DC418())
        return;
    if (!obj) {
        obj = func_0013B108(target, 0);
        if (!obj)
            return;
    }
    float d1 = obj->DistTo(*pos);
    float d2 = Dist_001DE8F0(*func_00114E18(obj), *target);
    float delta = d2 - d1;
    float speed = fabsf(delta) * Frames_001DE8F0();
    if (Frames_001DE8F0() * 360.0f < speed)
        return;
    *out = *out - (*out * delta) / (scale * 12320.0f);
}
