typedef int qword __attribute__((mode(TI)));
union Vec_002817F0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_002817F0() {}
    Vec_002817F0(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator-=(const Vec_002817F0& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator+=(const Vec_002817F0& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void Normalize();
};
extern "C" float sqrtf(float);
extern "C" float fabsf(float);
extern "C" void func_003233B8(Vec_002817F0*, Vec_002817F0*);
inline void Vec_002817F0::Normalize() { func_003233B8(this, this); }
inline Vec_002817F0 operator*(const Vec_002817F0& a, float k) { return Vec_002817F0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_002817F0 operator+(const Vec_002817F0& a, const Vec_002817F0& b)
{
    return Vec_002817F0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

extern "C" void func_00183CB8(void* p, void* pp);

struct Coll_002817F0 {
    Vec_002817F0 start;
    Vec_002817F0 end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0xA0 - 0x6A];
    Vec_002817F0 hit;
    Vec_002817F0 normal;
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
    char padC4[0xD4 - 0xC4];
    void* mD4;
    char padD8[0xE0 - 0xD8];
    bool Wall() { return fabsf(normal[1]) < 0.7070000172f; }
};
struct Box_002817F0 {
    Vec_002817F0 lo;
    Vec_002817F0 hi;
};
struct Target_002817F0 {
    Vec_002817F0 pos;
    Vec_002817F0 up;
    float m20;
};
struct State_002817F0 {
    int pad;
    int state;
    unsigned int time;
};
struct Sub_002817F0 {
    char pad0[0xA8];
    State_002817F0 mA8;
};
struct Skater_002817F0 {
    char pad0[0x20];
    int m20;
    char pad24[0x180 - 0x24];
    int m180;
    bool IsState0() { return !m180 && !m20; }
    bool IsState1() { return !m180 && m20 == 1; }
};
struct Holder_002817F0 {
    char pad0[0x34];
    Skater_002817F0* m34;
};
struct Ctrl_002817F0 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x60 - 0x20];
    Vec_002817F0 m60;
    char pad70[0xB54 - 0x70];
    float mB54;
};
struct Phys_002817F0 {
    char pad0[0x60];
    float m60;
    float m64;
    float m68;
};

extern "C" unsigned int func_0010FC30();
extern "C" void func_00209240(Coll_002817F0* c);
extern "C" bool func_002093E8(Coll_002817F0* c, int a, int b);
extern "C" void* func_001DAD40();
extern "C" void func_001DADB0(void* l);
extern "C" void func_001DA948(void* l, Box_002817F0* b);
extern "C" Box_002817F0* func_001022D8(Box_002817F0* b);
extern "C" void func_00102358(Box_002817F0* b, Vec_002817F0* p);
extern "C" void func_00101890(Vec_002817F0* v, Vec_002817F0* n);
extern "C" float func_001E5318(unsigned int name, int v);
extern "C" float func_002032A0(unsigned int name, int v);
extern "C" void* func_001E5548(unsigned int name, int v);
extern "C" int func_001E7EB0(void* p, unsigned int name, float* out, int req);
extern "C" Phys_002817F0* func_00185578(void* obj, unsigned int name);
struct Obj_002817F0;
extern "C" float func_00282B58(Obj_002817F0* o);
extern "C" float func_00282C38(Obj_002817F0* o, float a, float b, float c);

static inline void Set_002817F0(State_002817F0* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}
static inline float Max_002817F0(float a, float b) { return a > b ? a : b; }
static inline float Min_002817F0(float a, float b) { return a < b ? a : b; }
static inline float Param_002817F0(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}

struct Obj_002817F0 {
    char pad0[0xC];
    void* mC;
    char pad10[0x5B0 - 0x10];
    Sub_002817F0* m5B0;
    char pad5B4[0x5B8 - 0x5B4];
    Holder_002817F0* m5B8;
    Ctrl_002817F0* m5BC;
    int Find(int up, Vec_002817F0* pos, Vec_002817F0* from, Vec_002817F0* vel, Target_002817F0* out);
};

int Obj_002817F0::Find(int up, Vec_002817F0* pos, Vec_002817F0* from, Vec_002817F0* vel, Target_002817F0* out)
{
    Vec_002817F0 dir;
    Vec_002817F0 hit;
    if (m5B8->m34->IsState0()) {
        dir = *vel;
        dir[1] = 0.0f;
        float y = dir[1];
        float len = sqrtf(dir[0] * dir[0] + dir[2] * dir[2]);
        if (len < 0.01f)
            return 0;
        float inv = 1.0f / len;
        dir.Set(dir[0] * inv, y, dir[2] * inv, dir[3] * inv);
    } else {
        dir = m5BC->m60;
    }
    Vec_002817F0 p = *from;
    p[1] = Max_002817F0((*pos)[1], (*from)[1]);
    bool found = false;
    float range = 500.0f;
    float yoff = 0.0f;
    if (m5B8->m34->IsState1()) {
        if (!m5BC->m1C) {
            yoff = 200.0f;
            range = func_001E5318(0xE50A9D56, 0);
        } else {
            p -= dir * 12.0f;
        }
    }
    Vec_002817F0 q;
    Coll_002817F0 c;
    func_00209240(&c);
    float d = 0.01f;
    void* list = func_001DAD40();
    Box_002817F0 box;
    func_001022D8(&box);
    q = p;
    q[1] += yoff;
    func_00102358(&box, &q);
    q[1] -= 4200.0f;
    func_00102358(&box, &q);
    q = p + dir * range;
    q[1] += yoff;
    func_00102358(&box, &q);
    q[1] -= 4200.0f;
    func_00102358(&box, &q);
    func_001DA948(list, &box);
    c.mD4 = list;
    Vec_002817F0 nrm;
    Vec_002817F0 n;
    while (d < range) {
        c.end = c.start = p + dir * d;
        c.end[1] -= 4000.0f;
        c.start[1] += yoff;
        if (func_002093E8(&c, 1, 0) && (c.m68 & 8) && c.Wall()) {
            nrm = c.normal;
            Vec_002817F0* pn = &n;
            *pn = nrm;
            n[1] = 0.0f;
            pn->Normalize();
            if (m5B8->m34->IsState1() && m5BC->m1C == 1) {
                float dt = dir[0] * n[0] + dir[1] * n[1] + dir[2] * n[2];
                found = dt <= -0.25f || 0.05f <= dt;
            } else {
                float dt = dir[0] * n[0] + dir[1] * n[1] + dir[2] * n[2];
                found = 0.05f <= dt;
            }
            if (found) {
                hit = c.hit;
                break;
            }
        }
        if (100.0f < d)
            d += 24.0f;
        d += 3.0f;
    }
    if (!found) {
        func_001DADB0(list);
        Coll_002817F0::Ref* r = &c.mC0;
        r->Release();
        return 0;
    }
    float hy = hit[1];
    Vec_002817F0 v;
    {
        float x = hit[0] - (*pos)[0];
        float z = hit[2] - (*pos)[2];
        float w = hit[3] - (*pos)[3];
        v[1] = 0.0f;
        v[0] = x;
        v[2] = z;
        v[3] = w;
    }
    float zero = v[1];
    d = sqrtf(v[0] * v[0] + v[2] * v[2]);
    if (v[0] * dir[0] + v[2] * dir[2] < zero)
        d = -d;
    float inv = 1.0f / d;
    dir = Vec_002817F0(v[0] * inv, zero, v[2] * inv, v[3] * inv);
    Vec_002817F0 saved = *vel;
    if (m5B8->m34->IsState1()) {
        func_00101890(vel, &dir);
        (*vel)[1] = saved[1];
    }
    float speed = sqrtf((*vel)[0] * (*vel)[0] + (*vel)[2] * (*vel)[2]);
    if (m5B8->m34->IsState1()) {
        Ctrl_002817F0* k = m5BC;
        float lo = Param_002817F0(0xCC461B87);
        float hi = Param_002817F0(0x7213EF07);
        float s = lo + (hi - lo) * k->mB54;
        if (speed < s) {
            (*vel)[0] = s * func_00185578(mC, 0x726E85AA)->m60;
            (*vel)[2] = s * func_00185578(mC, 0x726E85AA)->m68;
            speed = s;
        }
    }
    if (up) {
        (*vel)[1] = Max_002817F0((*vel)[1], func_002032A0(0x95A79C32, 0));
    }
    if (!m5B8->m34->IsState1() || m5BC->m1C) {
        (*vel)[1] = Min_002817F0((*vel)[1], func_002032A0(0x95A79C32, 0) * 2.0f);
    }
    Set_002817F0(&m5B0->mA8, 1);
    float g = func_00282B58(this);
    Set_002817F0(&m5B0->mA8, 0);
    float py;
    float top;
    if (0.0f < d && 0.00009999999747f < speed) {
        float t = d / speed;
        float ht = t * 0.5f;
        top = (*pos)[1] + (*vel)[1] * t + g * ht * t;
        py = (*pos)[1];
    } else {
        top = (*pos)[1];
        py = top;
    }
    if (m5B8->m34->IsState1()) {
        float vy = (*vel)[1];
        if (0.0f < vy && py < hit[1]) {
            float h = py + vy * vy / (g * -2.0f);
            if (fabsf(d) / speed < vy / -g)
                top = h;
        }
    }
    if (top < hit[1]) {
        func_001DADB0(list);
        *vel = saved;
        Coll_002817F0::Ref* r = &c.mC0;
        r->Release();
        return 0;
    }
    Set_002817F0(&m5B0->mA8, 1);
    float tm = func_00282C38(this, hy, (*pos)[1], (*vel)[1]);
    Set_002817F0(&m5B0->mA8, 0);
    if (tm < func_001E5318(0x32C20F7E, 0)) {
        func_001DADB0(list);
        *vel = saved;
        Coll_002817F0::Ref* r = &c.mC0;
        r->Release();
        return 0;
    }
    found = false;
    while (hit[1] < top) {
        c.start = *pos;
        Set_002817F0(&m5B0->mA8, 1);
        float h = func_00282C38(this, hit[1], (*pos)[1], (*vel)[1]) * 0.5f;
        Set_002817F0(&m5B0->mA8, 0);
        Vec_002817F0 e = *pos;
        float hh = h * h * 0.5f;
        e[1] = (*pos)[1] + (*vel)[1] * h + g * hh;
        e += dir * (d * 0.5f / h * h);
        c.end = e;
        if (!func_002093E8(&c, 1, 0)) {
            c.start = c.end;
            c.end = hit;
            c.end[1] += 1.0f;
            if (!func_002093E8(&c, 1, 0)) {
                found = true;
                break;
            }
        }
        hit[1] += 24.0f;
    }
    if (!found) {
        func_001DADB0(list);
        *vel = saved;
        Coll_002817F0::Ref* r = &c.mC0;
        r->Release();
        return 0;
    }
    func_001DADB0(list);
    out->pos = hit;
    out->up = nrm;
    out->m20 = hy;
    Coll_002817F0::Ref* r = &c.mC0;
    r->Release();
    return 1;
}
