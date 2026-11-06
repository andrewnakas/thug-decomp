/* fuzzy: 81.7 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0024EA20 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
};

struct Mat_0024EA20 {
    Vec_0024EA20 row[4];
};

extern "C" void func_00323298(Vec_0024EA20* dst, Mat_0024EA20* m, Vec_0024EA20* src);
static inline void Xform_0024EA20(Vec_0024EA20* v, Mat_0024EA20* m) { func_00323298(v, m, v); }

struct Comp_0024EA20 {
    char pad[0x260];
    int m260;
};

struct Ent_0024EA20 {
    char pad[0x50];
    Vec_0024EA20 m50;
    char pad60[0x10];
    Mat_0024EA20 m70;
};

extern void* D_0038FC78;
extern "C" float sqrtf(float);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" Ent_0024EA20* func_00184D70(unsigned int id);
extern "C" Comp_0024EA20* func_00185578(void* obj, unsigned int name);
extern "C" void func_0013EF90(Vec_0024EA20* out, int a);
extern "C" void func_00323298(Vec_0024EA20* dst, Mat_0024EA20* m, Vec_0024EA20* src);
extern "C" int func_001325F0(Vec_0024EA20* v, float r);
extern "C" void* func_0022DD38(void* self);
extern "C" void* func_00203EC0(void* p);
extern "C" Vec_0024EA20* func_00114E18(void* p);

struct Obj_0024EA20 {
    char pad[0x20];
    void* m20;
    bool Fn();
};

bool Obj_0024EA20::Fn()
{
    bool r = false;
    unsigned int id;
    func_001E8398(m20, 0xD262ED09, &id, 1);
    Ent_0024EA20* e = func_00184D70(id);
    if (e) {
        Vec_0024EA20 t;
        func_0013EF90(&t, func_00185578(e, 0x286A8D26)->m260);
        Vec_0024EA20 p = t;
        p.w = 1.0f;
        Xform_0024EA20(&p, &e->m70);
        p.x += e->m50.x;
        p.y += e->m50.y;
        p.z += e->m50.z;
        p.w += e->m50.w;
        if (func_001325F0(&p, 6.0f)) {
            Vec_0024EA20* s = func_00114E18(func_00203EC0(func_0022DD38(D_0038FC78)));
            Vec_0024EA20 d;
            d.x = s->x - e->m50.x;
            d.y = s->y - e->m50.y;
            d.z = s->z - e->m50.z;
            d.w = s->w - e->m50.w;
            float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
            int maxd;
            func_001E7DE8(m20, 0x856FAB92, &maxd, 1);
            if (len < (float)maxd) r = true;
        }
    }
    return r;
}
