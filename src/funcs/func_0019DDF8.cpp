extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00102FD0(void* mem);

struct Vec_0019DDF8 {
    float x, y, z, w;
};

struct Mat_0019DDF8 {
    float m[4][4];
};

extern "C" void func_00100498(void* m, Vec_0019DDF8* out);
extern "C" void func_00100200(Mat_0019DDF8* q, float x, float y, float z);
extern "C" void func_00103000(void* slerp, void* m, Mat_0019DDF8* q);

struct Obj_0019DDF8 {
    char pad0[0x3C];
    int m3C;
    char pad40[0x4C - 0x40];
    int m4C;
    float m50;
    char pad54[0x64 - 0x54];
    void* m64;
    char pad68[0xC0 - 0x68];
    char mC0[0x40];
    void Fn();
};

extern "C" void func_0019DCE8(Obj_0019DDF8* self, Vec_0019DDF8* v);
extern "C" void func_0019DD50(Obj_0019DDF8* self, Vec_0019DDF8* v);
extern "C" void func_0019DDB0(Obj_0019DDF8* self, Vec_0019DDF8* v);

void Obj_0019DDF8::Fn()
{
    Vec_0019DDF8 r;
    func_00100498(mC0, &r);
    m50 = 0.0f;
    switch (m3C) {
    case 1:
        func_0019DCE8(this, &r);
        break;
    case 2:
        func_0019DD50(this, &r);
        break;
    case 3:
        func_0019DDB0(this, &r);
        break;
    case 0:
    default:
        return;
    }
    if (!m64)
        m64 = func_00102FD0(func_0010A638(D_00388A70, 0xA0, 1, 0));
    Mat_0019DDF8 q;
    func_00100200(&q, r.x, r.y, r.z);
    func_00103000(m64, mC0, &q);
    m4C = 1;
}
