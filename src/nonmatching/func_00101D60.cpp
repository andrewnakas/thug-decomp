/* fuzzy: 86.0 */
struct Vec {
    float x, y, z, w;
};

extern "C" Vec* func_001016A8(Vec* v, const Vec* n);
extern "C" void func_003233B8(Vec* dst, Vec* src);
extern "C" float func_003412F0(float x);

static inline float Clamp(float v, float lo, float hi)
{
    if (v > hi) {
        v = hi;
    }
    if (v < lo) {
        v = lo;
    }
    return v;
}

extern "C" float func_00101D60(Vec* a, Vec* b, Vec* n)
{
    func_003233B8(n, n);
    func_001016A8(a, n);
    func_001016A8(b, n);
    func_003233B8(a, a);
    func_003233B8(b, b);
    Vec c;
    c.x = n->y * a->z - n->z * a->y;
    c.y = n->z * a->x - n->x * a->z;
    c.z = n->x * a->y - n->y * a->x;
    c.w = 0.0f;
    float s = c.x * b->x + c.y * b->y + c.z * b->z;
    float d = a->x * b->x + a->y * b->y + a->z * b->z;
    float ang = func_003412F0(Clamp(d, -1.0f, 1.0f));
    if (s < 0.0f) {
        ang = -ang;
    }
    return ang;
}
