typedef int qword __attribute__((mode(TI)));

struct Vec_00143AA0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00143AA0() {}
    Vec_00143AA0(float ax, float ay, float az, float aw) : x(ax), y(ay), z(az), w(aw) {}
};

static inline Vec_00143AA0 operator-(const Vec_00143AA0& a, const Vec_00143AA0& b)
{
    return Vec_00143AA0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Box_00143AA0 {
    Vec_00143AA0 min;
    Vec_00143AA0 max;
};

struct Shape_00143AA0 {
    char pad[0x10];
    Box_00143AA0 box;
};

struct Obj_00143AA0 {
    void* m0;
    int m4;
    Shape_00143AA0* m8;
};

struct Entry_00143AA0 {
    Vec_00143AA0 pos;
    int id;
    unsigned int time;
};

extern "C" unsigned int func_0010FC30();
extern "C" void func_00144680(void* list);
extern "C" Entry_00143AA0* func_00144690(void* list, int a);
extern "C" void func_00144740(void* list, Entry_00143AA0** e);
extern "C" void func_00144970(void* list, void** k, Entry_00143AA0* e);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" int func_00105520(const char* name);
extern "C" void* func_00139468(void* mgr, int crc);
extern "C" Box_00143AA0* func_00101F40(Box_00143AA0* b, Vec_00143AA0* c, Vec_00143AA0* r);
extern "C" void func_00102328(Box_00143AA0* b, Vec_00143AA0* p);
extern "C" void func_00102358(Box_00143AA0* b, Vec_00143AA0* p);
extern "C" void* func_001324B8(Box_00143AA0* b);
extern "C" Obj_00143AA0** func_00208E80(void* w, Box_00143AA0* b);
extern "C" void* func_001317D0(void* p);
extern "C" int func_0014F538(void** a, Obj_00143AA0** b, Vec_00143AA0* pos, Vec_00143AA0* r, float f0, float f1, void* t, Entry_00143AA0* e);

extern void* D_0038A638[1];
extern void* D_00388A70;
extern void* D_00393EF8;
extern void* D_003C39B0[];
extern Obj_00143AA0* D_003C3BB0[];

static inline bool Overlap(const Box_00143AA0& a, const Shape_00143AA0* s)
{
    if (s->box.min.x > a.max.x || a.min.x > s->box.max.x ||
        s->box.min.z > a.max.z || a.min.z > s->box.max.z ||
        s->box.min.y > a.max.y || a.min.y > s->box.max.y) {
        return false;
    }
    return true;
}

extern "C" int func_00143AA0(Vec_00143AA0* pos, Vec_00143AA0* radius, const char* name, int id, float f0, float f1)
{
    Entry_00143AA0* e = 0;
    if (id) {
        unsigned int now = func_0010FC30();
        func_00144680(D_0038A638[0]);
        e = func_00144690(D_0038A638[0], 0);
        if (e) {
            do {
                Entry_00143AA0* dead = 0;
                if (now < e->time || now - e->time > 500) {
                    dead = e;
                } else if (e->id == id) {
                    Vec_00143AA0 d = *pos - e->pos;
                    if (d.x * d.x + d.y * d.y + d.z * d.z < 4356.0f) break;
                }
                e = func_00144690(D_0038A638[0], 0);
                if (dead) {
                    Entry_00143AA0* t = dead;
                    func_00144740(D_0038A638[0], &t);
                    func_0010A8D8(D_00388A70, dead);
                }
            } while (e);
        }
        if (!e) {
            e = (Entry_00143AA0*)func_0010A638(D_00388A70, 0x20, 1, 0);
            e->id = id;
            e->pos = *pos;
            e->time = now;
            void* k = e;
            func_00144970(D_0038A638[0], &k, e);
            return 1;
        }
    }
    void* type = func_00139468(D_00393EF8, func_00105520(name));
    Box_00143AA0 b1;
    func_00101F40(&b1, pos, radius);
    Box_00143AA0 b2;
    func_00102328(&b2, &b1.min);
    func_00102358(&b2, &b1.max);
    Obj_00143AA0** list = func_00208E80(func_001324B8(&b1), &b1);
    if (!list) return 0;
    int n = 0;
    Obj_00143AA0* o;
    while ((o = *list) != 0) {
        if (o->m8) {
            if (Overlap(b2, o->m8)) {
                void* v = func_001317D0(o->m0);
                D_003C3BB0[n] = o;
                D_003C39B0[n] = v;
                n++;
            }
            list++;
        }
    }
    if (n > 0) {
        D_003C39B0[n] = 0;
        D_003C3BB0[n] = 0;
        int ret;
        if (!id || pos->x != e->pos.x || pos->z != e->pos.z)
            ret = func_0014F538(D_003C39B0, D_003C3BB0, pos, radius, f0, f1, type, e);
        else
            ret = 0;

        if (e) {
            e->pos = *pos;
            e->time = func_0010FC30();
        }
        return ret;
    }
    return 0;
}
