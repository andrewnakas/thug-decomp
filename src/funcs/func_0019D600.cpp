typedef int qword_0019D600 __attribute__((mode(TI)));

struct Vec_0019D600 {
    union {
        struct { float x, y, z, w; };
        qword_0019D600 q;
    };
    Vec_0019D600() {}
    Vec_0019D600(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Obj_0019D600;
extern "C" int func_001E7FA8(void* params, unsigned int name, Vec_0019D600* out, int req);
extern "C" int func_001E8708(void* params, unsigned int name);
extern "C" void func_001019E0(Vec_0019D600* v);
extern "C" void func_0019E748(Obj_0019D600* o, Vec_0019D600* v);

struct Obj_0019D600 {
    char pad[0x1C];
    int m1C;
    int Method(unsigned int name, void* params);
};

int Obj_0019D600::Method(unsigned int name, void* params)
{
    switch (name) {
    case 0xF9055D81:
        m1C &= ~1;
        return 1;
    case 0xF64EF88E:
        m1C |= 1;
        return 1;
    case 0xFEA0E952: {
        Vec_0019D600 v(0.0f, 0.0f, 0.0f, 1.0f);
        func_001E7FA8(params, 0, &v, 0);
        if (func_001E8708(params, 0x26AF9DC9))
            func_001019E0(&v);
        func_0019E748(this, &v);
        return 1;
    }
    }
    return 2;
}
