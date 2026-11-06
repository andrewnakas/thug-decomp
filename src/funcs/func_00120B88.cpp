typedef int qword __attribute__((mode(TI)));

struct Vec_00120B88 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00120B88(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern void* D_00389518;
extern void* D_0038951C;
extern "C" void func_0013EDD0(void* p, Vec_00120B88* v);
extern "C" void func_0011E060(void* p);

extern "C" int func_00120B88()
{
    Vec_00120B88 v(1.0f, 1.0f, 1.0f, 1.0f);
    func_0013EDD0(D_00389518, &v);
    if (!D_0038951C) {
        return 0;
    }
    func_0011E060(D_0038951C);
    return 1;
}
