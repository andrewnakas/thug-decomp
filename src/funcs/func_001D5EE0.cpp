typedef int qword_001D5EE0 __attribute__((mode(TI)));

struct Vec_001D5EE0 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001D5EE0 q;
    };
    Vec_001D5EE0() {}
    float LengthSqr() const { return x * x + y * y + z * z; }
    inline void Normalize();
};

struct Face8_001D5EE0 {
    char pad0[4];
    unsigned char v[3];
    char pad7;
};
struct Face10_001D5EE0 {
    char pad0[4];
    unsigned short v[3];
};
struct CVert_001D5EE0 {
    unsigned short x, y, z;
};
struct FVert_001D5EE0 {
    float x, y, z;
};

struct Geom_001D5EE0 {
    char pad0[0xA];
    unsigned char mA;
    unsigned char mB;
    union {
        Face8_001D5EE0* f8;
        Face10_001D5EE0* f10;
    } mC;
    Vec_001D5EE0 m10;
    char pad20[0x30 - 0x20];
    union {
        CVert_001D5EE0* c;
        FVert_001D5EE0* f;
    } m30;
};

static inline void GetVert_001D5EE0(Geom_001D5EE0* g, int i, Vec_001D5EE0& out)
{
    if (g->mB) {
        out = g->m10;
        out.x += g->m30.c[i].x * 0.0625f;
        out.y += g->m30.c[i].y * 0.0625f;
        out.z += g->m30.c[i].z * 0.0625f;
        out.w = 0.0f;
    } else {
        out.x = g->m30.f[i].x;
        out.y = g->m30.f[i].y;
        out.z = g->m30.f[i].z;
        out.w = 0.0f;
    }
}

struct Box_001D5EE0;

struct Point_001D5EE0 {
    Vec_001D5EE0 p;
    Vec_001D5EE0 dir;
    unsigned char edge;
};

struct Contact_001D5EE0 {
    Point_001D5EE0 pt[2];
    Vec_001D5EE0 normal;
    int id;
    unsigned char flag;
};

struct Out_001D5EE0 {
    Contact_001D5EE0 c[32];
    int count;
    unsigned short ignore;
    unsigned short require;
};

class Coll_001D5EE0 {
public:
    int m0;
    int m4;
    Geom_001D5EE0* m8;
    virtual void v0();
    virtual void v1();
    virtual unsigned int GetFlags(unsigned int face);
    bool Collect(void* sphere, Box_001D5EE0* box, Out_001D5EE0* out);
};

extern "C" unsigned short* func_001D8118(Geom_001D5EE0* g, Box_001D5EE0* box, unsigned int* count);
extern "C" int func_001D2530(void* sphere, Vec_001D5EE0* v0, Vec_001D5EE0* v1, Vec_001D5EE0* v2,
                             Vec_001D5EE0* hit, int* edges);
extern "C" void func_003233B8(Vec_001D5EE0* out, Vec_001D5EE0* in);
inline void Vec_001D5EE0::Normalize() { func_003233B8(this, this); }

static inline void Dir_001D5EE0(Vec_001D5EE0& r, const Vec_001D5EE0& a, const Vec_001D5EE0& b)
{
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    r.z = a.z - b.z;
    r.w = a.w - b.w;
}

bool Coll_001D5EE0::Collect(void* sphere, Box_001D5EE0* box, Out_001D5EE0* out)
{
    unsigned int count;
    unsigned short* idx = func_001D8118(m8, box, &count);
    for (unsigned int n = 0; n < count; n++, idx++) {
        unsigned int flags = GetFlags(n);
        if (flags & out->ignore) continue;
        if (~flags & out->require) continue;
        Vec_001D5EE0 v0;
        Vec_001D5EE0 v1;
        Vec_001D5EE0 v2;
        Geom_001D5EE0* g = m8;
        if (g->mA) {
            Face8_001D5EE0* f = &g->mC.f8[*idx];
            GetVert_001D5EE0(m8, f->v[0], v0);
            GetVert_001D5EE0(m8, f->v[1], v1);
            GetVert_001D5EE0(m8, f->v[2], v2);
        } else {
            Face10_001D5EE0* f = &g->mC.f10[*idx];
            GetVert_001D5EE0(m8, f->v[0], v0);
            GetVert_001D5EE0(m8, f->v[1], v1);
            GetVert_001D5EE0(m8, f->v[2], v2);
        }
        Vec_001D5EE0 hit[2];
        int edges[2];
        if (!func_001D2530(sphere, &v0, &v1, &v2, hit, edges)) continue;
        if (out->count == 32) return true;
        Contact_001D5EE0* c = &out->c[out->count];
        {
            Vec_001D5EE0 nrm;
            {
                Vec_001D5EE0 e1;
                Vec_001D5EE0 e2;
                Dir_001D5EE0(e1, v1, v0);
                Dir_001D5EE0(e2, v2, v0);
                nrm.x = e1.y * e2.z - e1.z * e2.y;
                nrm.y = e1.z * e2.x - e1.x * e2.z;
                nrm.z = e1.x * e2.y - e1.y * e2.x;
                nrm.w = 0.0f;
            }
            nrm.Normalize();
            c->normal = nrm;
        }
        if (c->normal.LengthSqr() <= 0.0f) continue;
        c->flag = flags & 0x40;
        c->id = m0;
        c->pt[0].p = hit[0];
        c->pt[1].p = hit[1];
        int k = 2;
        while (k--) {
            int e = edges[k];
            Point_001D5EE0* pt = &c->pt[k];
            pt->edge = e != 0;
            Vec_001D5EE0 d;
            switch (e) {
            case 0:
                /* Pinned by elimination: func_001D2530 stores only literal 1/2/3 (s1/s4 at 001D2758,
                   001D2870, 001D2944, 001D2A18, 001D2AF0) or $zero (001D30B4, 001D3360) into edges[],
                   so e is in {0..3}. The game's tree (001D655C beq 1, 001D6564 slti 2, then 2, 3)
                   needs a fourth case below 1: only 0 (no edge, cf. 'edge = e != 0') remains.
                   Bulk writes checked: edges (callee t1 -> s3) is written only by sw at 0/4(s3) and at
                   s3+4*s1 ($zero at 001D30B4, 001D319C, 001D3254); the callee's sq stores go through s2
                   (hit, t0) and its memsets (func_003315B8 at 001D2C94, 001D2CA4) hit its own stack. */
                break;
            case 1:
                Dir_001D5EE0(d, v1, v0);
                d.Normalize();
                pt->dir = d;
                break;
            case 2:
                Dir_001D5EE0(d, v2, v1);
                d.Normalize();
                pt->dir = d;
                break;
            case 3:
                Dir_001D5EE0(d, v0, v2);
                d.Normalize();
                pt->dir = d;
                break;
            }
        }
        out->count++;
    }
    return out->count > 0;
}
