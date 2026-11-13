/* fuzzy: 98.5 */
typedef int qword __attribute__((mode(TI)));
union Vec_001C9C38 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};

extern "C" float sqrtf(float);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
static inline float Param_001C9C38(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

extern "C" void func_00183CB8(void* p, void* pp);
struct Coll_001C9C38;
extern "C" Coll_001C9C38* func_00209240(Coll_001C9C38* c);
extern "C" int func_002093E8(Coll_001C9C38* c, int a, int b);
struct Coll_001C9C38 {
    Vec_001C9C38 m0;
    Vec_001C9C38 m10;
    char pad20[0xC0 - 0x20];
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" void func_0026B1B0(Vec_001C9C38* out, void* rail, int idx);
extern "C" void func_003233B8(Vec_001C9C38* out, Vec_001C9C38* in);

static inline void Add_001C9C38(Vec_001C9C38& r, const Vec_001C9C38& a, const Vec_001C9C38& b)
{
    r.c[0] = a[0] + b[0];
    r.c[1] = a[1] + b[1];
    r.c[2] = a[2] + b[2];
    r.c[3] = a[3] + b[3];
}
static inline void Sub_001C9C38(Vec_001C9C38& r, const Vec_001C9C38& a, const Vec_001C9C38& b)
{
    r.c[0] = a[0] - b[0];
    r.c[1] = a[1] - b[1];
    r.c[2] = a[2] - b[2];
    r.c[3] = a[3] - b[3];
}
static inline void Mul_001C9C38(Vec_001C9C38& r, const Vec_001C9C38& a, float k)
{
    r.c[0] = a[0] * k;
    r.c[1] = a[1] * k;
    r.c[2] = a[2] * k;
    r.c[3] = a[3] * k;
}
static inline void Neg_001C9C38(Vec_001C9C38& r, const Vec_001C9C38& a)
{
    r.c[0] = -a[0];
    r.c[1] = -a[1];
    r.c[2] = -a[2];
    r.c[3] = -a[3];
}

struct Obj_001C9C38 {
    char pad0[0xA24];
    void* mA24;
    int Probe(Vec_001C9C38* dir, Vec_001C9C38* pos, bool fwd, Vec_001C9C38* n, float t, Vec_001C9C38* d, int a, int b);
};

extern "C" int func_001CAC08(Obj_001C9C38* o, float* t, int a, int b, int* pa, int* pb);
extern "C" float func_001CB6F8(Obj_001C9C38* o);

int Obj_001C9C38::Probe(Vec_001C9C38* dir, Vec_001C9C38* pos, bool fwd, Vec_001C9C38* n, float t, Vec_001C9C38* d,
                        int a, int b)
{
    bool same = !fwd;
    if ((*n)[0] * (*d)[0] + (*n)[1] * (*d)[1] + (*n)[2] * (*d)[2] < 0.0f) same = fwd;
    Vec_001C9C38 v;
    if (fwd)
        v = *n;
    else
        Neg_001C9C38(v, *n);
    Vec_001C9C38 w = *dir;
    Vec_001C9C38 tmp;
    float len = sqrtf((*d)[0] * (*d)[0] + (*d)[1] * (*d)[1] + (*d)[2] * (*d)[2]);
    float dist = len * (same ? 1.0f - t : t);
    if (dist < Param_001C9C38(0x3344A6D0) + 1.0f) {
        if (same)
            t = t + 2.0f;
        else
            t = t + -2.0f;
        int na;
        int nb;
        if (func_001CAC08(this, &t, a, b, &na, &nb)) {
            float s = 1.0f;
            if (0.5f < t) s = -1.0f;
            Vec_001C9C38 diff;
            Vec_001C9C38 pa;
            Vec_001C9C38 pb;
            func_0026B1B0(&pa, mA24, na);
            func_0026B1B0(&pb, mA24, nb);
            Sub_001C9C38(diff, pa, pb);
            Mul_001C9C38(tmp, diff, s);
            tmp.c[1] = 0.0f;
            func_003233B8(&tmp, &tmp);
            float dot = (*dir)[0] * tmp[0] + (*dir)[1] * tmp[1] + (*dir)[2] * tmp[2];
            if (dot < 0.0f) {
                if (-0.87f < dot) {
                    v = tmp;
                    if (fwd) {
                        w.c[0] = v[2];
                        w.c[2] = -v[0];
                    } else {
                        w.c[0] = -v[2];
                        w.c[2] = v[0];
                    }
                }
            }
        }
    }
    Coll_001C9C38 c;
    func_00209240(&c);
    c.m0 = *pos;
    c.m0.c[1] += Param_001C9C38(0x84FF931C);
    Mul_001C9C38(tmp, *dir, Param_001C9C38(0xCBEB3D89));
    Sub_001C9C38(c.m0, c.m0, tmp);
    c.m10 = c.m0;
    Mul_001C9C38(tmp, v, Param_001C9C38(0x3344A6D0));
    Add_001C9C38(c.m10, c.m10, tmp);

    if (func_002093E8(&c, 1, 0)) {
        Coll_001C9C38::Ref* h = &c.mC0;
        h->Release();
        return 1;
    }
    c.m10 = c.m0;
    c.m10.c[1] += Param_001C9C38(0xC774DD6D);
    Mul_001C9C38(tmp, v, Param_001C9C38(0x3344A6D0));
    Add_001C9C38(c.m10, c.m10, tmp);
    if (func_002093E8(&c, 1, 0)) {
        Coll_001C9C38::Ref* h = &c.mC0;
        h->Release();
        return 1;
    }
    c.m10 = c.m0;
    c.m10.c[1] += Param_001C9C38(0xC774DD6D) * 0.5f;
    Mul_001C9C38(tmp, v, Param_001C9C38(0x3344A6D0));
    Add_001C9C38(c.m10, c.m10, tmp);
    if (func_002093E8(&c, 1, 0)) {
        Coll_001C9C38::Ref* h = &c.mC0;
        h->Release();
        return 1;
    }
    c.m10 = c.m0;
    float hgt = Param_001C9C38(0x84FF931C);
    c.m10.c[1] += func_001CB6F8(this) - hgt - 1.0f;
    Mul_001C9C38(tmp, w, Param_001C9C38(0xC3263E6E));
    Add_001C9C38(c.m10, c.m10, tmp);
    Mul_001C9C38(tmp, v, Param_001C9C38(0x3344A6D0));
    Add_001C9C38(c.m10, c.m10, tmp);
    if (same) {
        func_003233B8(d, d);
        Neg_001C9C38(tmp, *d);
    } else {
        func_003233B8(d, d);
        tmp = *d;
    }
    Add_001C9C38(c.m10, c.m10, tmp);
    if (func_002093E8(&c, 1, 0)) {
        Coll_001C9C38::Ref* h = &c.mC0;
        h->Release();
        return 1;
    }
    c.m10 = c.m0;
    c.m10.c[1] -= Param_001C9C38(0xC774DD6D) * 0.5f;
    Mul_001C9C38(tmp, w, Param_001C9C38(0xC3263E6E));
    Add_001C9C38(c.m10, c.m10, tmp);
    Mul_001C9C38(tmp, v, Param_001C9C38(0x3344A6D0));
    Add_001C9C38(c.m10, c.m10, tmp);
    if (func_002093E8(&c, 1, 0)) {
        Coll_001C9C38::Ref* h = &c.mC0;
        h->Release();
        return 1;
    }
    Coll_001C9C38::Ref* h = &c.mC0;
    h->Release();
    return 0;
}
