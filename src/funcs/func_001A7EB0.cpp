typedef int qword_001A7EB0 __attribute__((mode(TI)));

struct Vec_001A7EB0 {
    union {
        struct { float x, y, z, w; };
        qword_001A7EB0 q;
    };
    Vec_001A7EB0() {}
    Vec_001A7EB0(const Vec_001A7EB0& o) { q = o.q; }
    Vec_001A7EB0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Obj_001A7EB0;
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_001A7EB0* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001019E0(Vec_001A7EB0* v);
extern "C" int func_001A7BA0(Obj_001A7EB0* o, void* params, int a, Vec_001A7EB0 v, int b);

struct Model_001A7EB0 {
    char pad[0x50];
    Vec_001A7EB0 m50;
};

struct Obj_001A7EB0 {
    char pad[0xC];
    Model_001A7EB0* mC;
    void Method(void* params, int a, int world);
};

void Obj_001A7EB0::Method(void* params, int a, int world)
{
    Vec_001A7EB0 v(0.0f, 0.0f, 0.0f, 1.0f);
    func_001E7FA8(params, 0, &v, 0);
    if (func_001E8708(params, 0x26AF9DC9))
        func_001019E0(&v);
    if (!world) {
        Model_001A7EB0* m = mC;
        v.x += m->m50.x;
        v.y += m->m50.y;
        v.z += m->m50.z;
        v.w += m->m50.w;
    }
    func_001A7BA0(this, params, a, v, -1);
}
