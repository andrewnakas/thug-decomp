typedef int qword __attribute__((mode(TI)));
union Vec_00281438 {
    qword q;
    struct { float x, y, z, w; } f;
    void Normalize();
};
struct V3_00281438 { float x, y, z; };

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" float fabsf(float);

struct Coll_00281438 {
    Vec_00281438 start;
    Vec_00281438 end;
    char pad20[0x68 - 0x20];
    unsigned short m68;
    char pad6A[0xA0 - 0x6A];
    Vec_00281438 hit;
    Vec_00281438 normal;
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
    bool Wall() { return fabsf(normal.f.y) < 0.7070000172f; }
};
struct Box_00281438 {
    Vec_00281438 lo;
    Vec_00281438 hi;
};

extern "C" void func_00209240(Coll_00281438* c);
extern "C" bool func_002093E8(Coll_00281438* c, int a, int b);
extern "C" void* func_001DAD40();
extern "C" void func_001DADB0(void* l);
extern "C" void func_001DA948(void* l, Box_00281438* b);
extern "C" void func_001022D8(Box_00281438* b);
extern "C" void func_00102358(Box_00281438* b, Vec_00281438* p);
extern "C" void func_003233B8(Vec_00281438*, Vec_00281438*);
inline void Vec_00281438::Normalize() { func_003233B8(this, this); }

struct Body_00281438 {
    char pad[0x50];
    Vec_00281438 m50;
};

struct Obj_00281438 {
    char pad0[0xC];
    Body_00281438* mC;
    int Find(Vec_00281438* dir, V3_00281438* n, int* out, Vec_00281438* hit, Vec_00281438* nrm);
};

int Obj_00281438::Find(Vec_00281438* dir, V3_00281438* n, int* out, Vec_00281438* hit, Vec_00281438* nrm)
{
    Coll_00281438 c;
    func_00209240(&c);
    float lo = 10.0f;
    void* list = func_001DAD40();
    Box_00281438 box;
    Vec_00281438 p;
    Vec_00281438 u;
    Vec_00281438 t;
    Box_00281438* pb = &box;
    func_001022D8(pb);
    Vec_00281438* pp = &p;
    {
        float x = dir->f.x * lo; float y = dir->f.y * lo; float z = dir->f.z * lo; float w = dir->f.w * lo;
        t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
    }
    {
        Body_00281438* b = mC;
        float x = b->m50.f.x + t.f.x; float y = b->m50.f.y + t.f.y; float z = b->m50.f.z + t.f.z; float w = b->m50.f.w + t.f.w;
        u.f.x = x; u.f.y = y; u.f.z = z; u.f.w = w;
    }
    p = u;
    func_00102358(pb, pp);
    p.f.y -= 4000.0f;
    func_00102358(pb, pp);
    {
        float x = dir->f.x * 500.0f; float y = dir->f.y * 500.0f; float z = dir->f.z * 500.0f; float w = dir->f.w * 500.0f;
        t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
    }
    {
        Body_00281438* b = mC;
        float x = b->m50.f.x + t.f.x; float y = b->m50.f.y + t.f.y; float z = b->m50.f.z + t.f.z; float w = b->m50.f.w + t.f.w;
        u.f.x = x; u.f.y = y; u.f.z = z; u.f.w = w;
    }
    p = u;
    func_00102358(pb, pp);
    p.f.y -= 4000.0f;
    func_00102358(pb, pp);
    func_001DA948(list, pb);
    c.mD4 = list;
    float d = lo;
    do {
        {
            float x = dir->f.x * d; float y = dir->f.y * d; float z = dir->f.z * d; float w = dir->f.w * d;
            t.f.x = x; t.f.y = y; t.f.z = z; t.f.w = w;
        }
        {
            Body_00281438* b = mC;
            float x = b->m50.f.x + t.f.x; float y = b->m50.f.y + t.f.y; float z = b->m50.f.z + t.f.z; float w = b->m50.f.w + t.f.w;
            u.f.x = x; u.f.y = y; u.f.z = z; u.f.w = w;
        }
        c.end = u;
        c.start = u;
        c.end.f.y -= 4000.0f;
        if (func_002093E8(&c, 1, 0) && (c.m68 & 8) && c.Wall()) {
            u = c.normal;
            u.f.y = 0.0f;
            u.Normalize();
            float dt = n->x * u.f.x + n->y * u.f.y + n->z * u.f.z;
            if (dt <= 0.9499999881f) {
                *hit = c.hit;
                *nrm = c.normal;
                *out = -0.8659999967f < dt;
                func_001DADB0(list);
                Coll_00281438::Ref* r = &c.mC0;
                r->Release();
                return 1;
            }
        }
        d += 6.0f;
    } while (d < 500.0f);
    func_001DADB0(list);
    Coll_00281438::Ref* r = &c.mC0;
    r->Release();
    return 0;
}
