typedef int qword __attribute__((mode(TI)));

struct Vec {
    union {
        struct { float x, y, z, w; };
        float v[4];
        qword q;
    };
    Vec() {}
    Vec(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 0.0f; }
};

extern "C" float sqrtf(float);
extern "C" Vec* func_001016A8(Vec* v, const Vec* n);
extern "C" void func_003233B8(Vec* dst, Vec* src);
extern "C" float func_003412F0(float x);
extern "C" float func_001018F8(const Vec* v, int* idx);

extern "C" float func_00101A10(Vec* m, const Vec* dir, int i, int j)
{
    Vec p;
    Vec* n = &m[j];
    p.q = dir->q;
    func_001016A8(&p, n);
    if (sqrtf(p.x * p.x + p.y * p.y + p.z * p.z) == 0.0f) {
        return 0.0f;
    }
    func_003233B8(&p, &p);
    Vec* a = &m[i];
    float d = a->x * p.x + a->y * p.y + a->z * p.z;
    if (d > 1.0f) {
        d = 1.0f;
    }
    if (d < -1.0f) {
        d = -1.0f;
    }
    float ang = func_003412F0(d);
    float nang = -ang;
    float ay = a->y, az = a->z, ax = a->x;
    Vec c;
    c.x = ay * p.z - az * p.y;
    c.y = az * p.x - ax * p.z;
    c.z = ax * p.y - ay * p.x;
    c.w = 0.0f;
    int idx;
    float r = func_001018F8(&c, &idx);
    float* e = &n->v[idx];
    bool s = r <= 0.0f;
    bool t = *e > 0.0f;
    if (s != t) {
        return ang;
    }
    return nang;
}
