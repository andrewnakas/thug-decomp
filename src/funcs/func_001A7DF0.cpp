typedef int qword_001A7DF0 __attribute__((mode(TI)));

struct Vec_001A7DF0 {
    union {
        struct { float x, y, z, w; };
        qword_001A7DF0 q;
    };
    Vec_001A7DF0() {}
    Vec_001A7DF0(const Vec_001A7DF0& o) { q = o.q; }
};

struct Obj_001A7DF0;
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_00229668(unsigned int id, int a);
extern "C" void func_0022A090(void* o, Vec_001A7DF0* out);
extern "C" int func_001A7BA0(Obj_001A7DF0* o, void* params, int a, Vec_001A7DF0 v, void* target);
extern "C" void func_001A6BB8(Obj_001A7DF0* o, void* target);

struct Obj_001A7DF0 {
    char pad[0x150];
    void* m150;
    void Method(void* params, int a);
};

void Obj_001A7DF0::Method(void* params, int a)
{
    unsigned int id = 0;
    func_001E8398(params, 0xA1DC81F9, &id, 0);
    if (id) {
        void* target = func_00229668(id, 1);
        Vec_001A7DF0 v;
        func_0022A090(target, &v);
        if (func_001A7BA0(this, params, a, v, target))
            func_001A6BB8(this, target);
        else
            m150 = target;
    }
}
