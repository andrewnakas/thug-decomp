/* fuzzy: 62.0 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Row_00199618 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Dot(const Row_00199618& o) const { return x * o.x + y * o.y + z * o.z; }
    Row_00199618& operator+=(const Row_00199618& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Vec_00199618 : Row_00199618 {
    Vec_00199618() {}
    Vec_00199618(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_00199618 Sub_00199618(const Row_00199618& a, const Row_00199618& b)
{
    return Vec_00199618(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_00199618 Add_00199618(const Row_00199618& a, const Row_00199618& b)
{
    return Vec_00199618(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_00199618 Scale_00199618(const Row_00199618& a, float s)
{
    return Vec_00199618(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline Vec_00199618 Cross_00199618(const Row_00199618& a, const Row_00199618& b)
{
    return Vec_00199618(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Mat3_00199618 {
    Row_00199618 r[3];
    Vec_00199618 Rotate(const Row_00199618& p) const
    {
        Vec_00199618 o;
        o.x = p.x * r[0].x + p.y * r[1].x + p.z * r[2].x;
        o.y = p.x * r[0].y + p.y * r[1].y + p.z * r[2].y;
        o.z = p.x * r[0].z + p.y * r[1].z + p.z * r[2].z;
        o.w = p.w;
        return o;
    }
};

// One contact gathered this frame.
struct Contact_00199618 {
    Row_00199618 p;
    Row_00199618 n;
    float m20;
    float m24;
    int m28;
    char pad2C[4];
};

extern Contact_00199618 D_003E49C0[];

// Triangle-vs-world query (0x2060 bytes, on the stack).
struct TriHit_00199618 {
    Row_00199618 pos;
    char pad10[0x10];
    signed char m20;
    char pad21[0xF];
};

struct TriFace_00199618 {
    TriHit_00199618 hit[2];
    Row_00199618 n;
    char pad70[0x10];
};

struct TriQuery_00199618 {
    Row_00199618 v[3];
    char pad30[0x1040 - 0x30];
    TriFace_00199618 face[32];
    int m_count;
    char pad2044[0xC];
    void* m2050;
    char pad2054[0xC];
};

struct Feeler_00199618 {
    Row_00199618 start;
    Row_00199618 end;
    char pad20[0x90 - 0x20];
    float m90;
    char pad94[0xC];
    Row_00199618 mA0;
    Row_00199618 mB0;
    void* mC0;
    char padC4[0x10];
    void* mD4;
    char padD8[8];
};

struct Tri_00199618 {
    char pad0[0x30];
    Row_00199618 v0;
    Row_00199618 e1;
    Row_00199618 e2;
    char pad60[0x30];
};

struct Owner_00199618 {
    char pad0[0xC];
    unsigned int mC;
};

extern "C" void func_00209A80(TriQuery_00199618* q);
extern "C" int func_00209B58(TriQuery_00199618* q, int a);
extern "C" void func_00209B80(TriQuery_00199618* q);
extern "C" void func_0020A348(TriQuery_00199618* q, int r, int g, int b, int a);
extern "C" void func_00209240(Feeler_00199618* f);
extern "C" int func_002093E8(Feeler_00199618* f, int a, int b);
extern "C" void func_00209A40(Feeler_00199618* f, int r, int g, int b, int a);
extern "C" void func_001BB1E0(void* sfx, int kind, TriQuery_00199618* q);
extern "C" void func_001BB080(void* sfx, int kind, Feeler_00199618* f);
extern "C" void func_00183CB8(void* p, void** slot);
extern "C" void func_001235E8(Row_00199618* a, Row_00199618* b, unsigned int c0, unsigned int c1, int a2);

struct Car_00199618;
extern "C" int func_00199508(Car_00199618* self, Contact_00199618* c);
extern "C" float func_001990F0(Car_00199618* self, Contact_00199618* c, Tri_00199618* t);
extern "C" int func_00199298(Car_00199618* self, Contact_00199618* c, TriQuery_00199618* q, Tri_00199618* t, int face,
                             int hit);
extern "C" float func_0019B610(Car_00199618* self, Row_00199618* r, Row_00199618* dir);

extern float D_00387824;
extern float D_00387828;
extern float D_0038782C;

struct Car_00199618 {
    char pad0[0xC];
    Owner_00199618* mC;
    char pad10[0x10];
    Row_00199618 m20;
    Row_00199618 m30;
    char pad40[0x10];
    Row_00199618 m50;
    char pad60[8];
    int m68;
    char pad6C[0x84 - 0x6C];
    float m84;
    char pad88[8];
    Row_00199618 m90;
    char padA0[0x10];
    Row_00199618 mB0;
    Row_00199618 mC0;
    Mat3_00199618 mD0;
    char pad100[0x120 - 0x100];
    unsigned int m120;
    char pad124[4];
    int m128;
    char pad12C[0x140 - 0x12C];
    Row_00199618 m140;
    Row_00199618 m150;
    char pad160[0x180 - 0x160];
    float m180;
    char pad184[0x1A0 - 0x184];
    float m1A0;
    float m1A4;
    float m1A8;
    float m1AC;
    float m1B0;
    char pad1B4[0x1E0 - 0x1B4];
    Tri_00199618 m1E0[2];
    char pad300[0x34C - 0x300];
    float m34C;
    char pad350[0x358 - 0x350];
    int m358;
    char pad35C[4];
    char m360[0x1370 - 0x360];
    float m1370;
    char pad1374[0x1380 - 0x1374];
    int m1380;
    char pad1384[0x1394 - 0x1384];
    void* m1394;

    bool Frozen()
    {
        bool frozen = false;
        if (m128 || (mC->mC & 1))
            frozen = true;
        return frozen;
    }
    void UpdateVel()
    {
        mB0 = Scale_00199618(m30, m180);
        mB0.w = 0.0f;
        mC0 = mD0.Rotate(m50);
    }
    void ApplyImpulse(const Row_00199618& r, const Row_00199618& imp)
    {
        m30 += imp;
        m50 += Cross_00199618(r, imp);
        UpdateVel();
    }
    void Collide();
};

// Casts one edge of the probe; returns true when the update must stop.
static inline bool Probe_00199618(Car_00199618* self, Feeler_00199618* f)
{
    if (func_002093E8(f, 0, 0)) {
        func_001BB080(self->m1394, 6, f);
        if (self->Frozen())
            return true;
        D_003E49C0[self->m68].p = f->mA0;
        D_003E49C0[self->m68].n = f->mB0;
        if (!func_00199508(self, &D_003E49C0[self->m68])) {
            Vec_00199618 d = Sub_00199618(f->start, f->end);
            D_003E49C0[self->m68].m20 = (1.0f - f->m90) * f->mB0.Dot(d);
            self->m68++;
            D_003E49C0[self->m68].m28 = 1;
        }
    }
    if (self->m1380) {
        func_00209A40(f, 0xFF, 0xFF, 0xFF, 1);
    }
    return false;
}

void Car_00199618::Collide()
{
    m1370 = 0.0f;
    int t = 1;
    TriQuery_00199618 q;
    func_00209A80(&q);
    Feeler_00199618 f;
    func_00209240(&f);
    q.m2050 = m360;
    f.mD4 = m360;
    m68 = 0;

    // Gather contacts for both collision triangles.
    do {
        Tri_00199618* tri = &m1E0[t];
        q.v[0] = tri->v0;
        q.v[1] = tri->e1;
        q.v[2] = tri->e2;
        if (func_00209B58(&q, 0)) {
            func_001BB1E0(m1394, 6, &q);
            if (Frozen())
                goto done;
            func_00209B80(&q);
            for (int i = q.m_count; i--;) {
                TriFace_00199618* face = &q.face[i];
                for (int j = 1; j != -1; j--) {
                    Contact_00199618* c = &D_003E49C0[m68];
                    c->p = face->hit[j].pos;
                    c->n = face->n;
                    c->m28 = 0;
                    signed char edge = face->hit[j].m20;
                    if (!func_00199508(this, c)) {
                        if (edge) {
                            c->m20 = func_001990F0(this, c, tri);
                        } else {
                            c->m20 = 0.0f;
                        }
                        m68++;
                    } else if (edge && func_00199298(this, c, &q, tri, i, j)) {
                        m68++;
                    }
                }
            }
        }
        if (m1380) {
            func_0020A348(&q, 0xFF, 0xFF, 0xFF, 1);
        }
        f.start = m20;
        f.end = q.v[0];
        if (Probe_00199618(this, &f))
            goto done;
        f.end += q.v[1];
        if (Probe_00199618(this, &f))
            goto done;
        f.end += q.v[2];
        if (Probe_00199618(this, &f))
            goto done;
        f.end = Sub_00199618(f.end, q.v[1]);
        if (Probe_00199618(this, &f))
            goto done;
        t--;
    } while (t != -1);

    if (m68 != 0) {
        for (int i = m68; i--;) {
            D_003E49C0[i].m24 = 0.0f;
        }
        Row_00199618 P = m30;
        Row_00199618 L = m50;
        Row_00199618 V = mB0;
        Row_00199618 W = mC0;

        // Normal impulses, up to 6 passes until every contact separates.
        int iter = 0;
        int done;
        do {
            iter++;
            done = 1;
            for (int i = m68; i--;) {
                Contact_00199618* c = &D_003E49C0[i];
                Vec_00199618 r = Sub_00199618(c->p, m20);
                Vec_00199618 v = Add_00199618(mB0, Cross_00199618(mC0, r));
                float vn = v.Dot(c->n);
                if (vn > 0.0f)
                    continue;
                done = 0;
                float j = -m1A0 * vn;
                j = (j - vn) * func_0019B610(this, &r, &c->n);
                c->m24 += j;
                ApplyImpulse(r, Scale_00199618(c->n, j));
            }
        } while (iter < 6 && !done);

        if (m1380 && m68) {
            // Debug display of the contacts (body compiled out in this build).
            for (int i = m68; i--;) {
            }
        }
        // Push-out forces.
        for (int i = m68; i--;) {
            Contact_00199618* c = &D_003E49C0[i];
            if (c->m20 <= 0.0f)
                continue;
            if (c->m20 > 2.0f)
                c->m20 = 2.0f;
            Vec_00199618 fo = Scale_00199618(c->n, m1A8 * c->m20);
            Vec_00199618 r = Sub_00199618(c->p, m20);
            m140 += fo;
            m150 += Cross_00199618(r, fo);
        }

        // Friction.
        float mu = (m84 > D_00387824) ? m1A4 : m1AC;
        for (int i = m68; i--;) {
            Contact_00199618* c = &D_003E49C0[i];
            if (c->m24 == 0.0f)
                continue;
            Vec_00199618 r = Sub_00199618(c->p, m20);
            Vec_00199618 v = Add_00199618(V, Cross_00199618(W, r));
            float vn = v.Dot(c->n);
            Vec_00199618 tan = Sub_00199618(v, Scale_00199618(c->n, vn));
            float len = sqrtf(tan.Dot(tan));
            if (len < D_00387828)
                continue;
            tan = Scale_00199618(tan, 1.0f / len);
            float j = len * func_0019B610(this, &r, &tan);
            float jmax = mu * c->m24;
            if (jmax < j)
                j = jmax;
            Vec_00199618 imp = Scale_00199618(tan, -j);
            ApplyImpulse(r, imp);
            P += imp;
            L += Cross_00199618(r, imp);
            V = Scale_00199618(P, m180);
            W = mD0.Rotate(L);
        }
        for (int i = m68; i--;) {
            float n = D_003E49C0[i].m24;
            if (m1370 < n)
                m1370 = n;
        }

        // Steering impulse along the ground.
        if (m34C != 0.0f && m120 >= 3 && !m358) {
            for (int i = m68; i--;) {
                Contact_00199618* c = &D_003E49C0[i];
                Vec_00199618 r = Sub_00199618(c->p, m20);
                Row_00199618 dir;
                dir.Set(-c->n.z, 0.0f, c->n.x, 1.0f);
                float s = m34C * m1B0 * m90.Dot(c->n) * c->m24;
                ApplyImpulse(r, Scale_00199618(dir, s));
                if (m1380) {
                    Row_00199618 a = Add_00199618(c->p, c->n);
                    Vec_00199618 b = Add_00199618(a, Scale_00199618(Scale_00199618(dir, s), D_0038782C));
                    func_001235E8(&a, &b, 0xFF6400FF, 0xFF6400FF, 1);
                }
            }
        }
    }
done:
    if (f.mC0) {
        func_00183CB8(f.mC0, &f.mC0);
        f.mC0 = 0;
    }
}
