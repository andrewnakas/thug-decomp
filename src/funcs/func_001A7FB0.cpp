typedef int qword_001A7FB0 __attribute__((mode(TI)));

struct Vec_001A7FB0 {
    union {
        struct { float x, y, z, w; };
        qword_001A7FB0 q;
    };
    Vec_001A7FB0() {}
    Vec_001A7FB0(const Vec_001A7FB0& o) { q = o.q; }
};

struct Obj_001A7FB0;
extern "C" int func_00229EB0(void* path);
extern "C" void* func_00229F48(void* path, int i);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" int func_00100030(int n);
extern "C" void func_0022A090(void* o, Vec_001A7FB0* out);
extern "C" int func_001A7BA0(Obj_001A7FB0* o, void* params, int a, Vec_001A7FB0 v, int b);
extern "C" void func_001A6BB8(Obj_001A7FB0* o, void* node);

struct Obj_001A7FB0 {
    char pad[0x150];
    void* m150;
    char pad154[0x218 - 0x154];
    void* m218;
    void Method(void* params, int a);
};

void Obj_001A7FB0::Method(void* params, int a)
{
    int index = 0;
    int count = func_00229EB0(m218);
    if (count) {
        if (func_001E7DE8(params, 0xE85997D0, &index, 0))
            index = index - 1;
        else if (count >= 2 && func_001E8708(params, 0x90A1C52A))
            index = func_00100030(count);
        void* node = func_00229F48(m218, index);
        Vec_001A7FB0 v;
        func_0022A090(node, &v);
        if (func_001A7BA0(this, params, a, v, -1))
            func_001A6BB8(this, node);
        else
            m150 = node;
    }
}
