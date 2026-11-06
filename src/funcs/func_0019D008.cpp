typedef int qword __attribute__((mode(TI)));

struct Vec_0019D008 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0019D008() {}
    Vec_0019D008(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};


struct Src_0019D008 {
    char pad0[0x90];
    Vec_0019D008 m90;
};

struct State_0019D008 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x28 - 0x20];
    int m28;
    int m2C;
};

class Comp_0019D008 {
public:
    char pad0[0x18];
    virtual void V0();
    virtual void V1();
};

extern "C" Comp_0019D008* func_00185578(void* obj, unsigned int name);
extern "C" void func_003233B8(Vec_0019D008* out, Vec_0019D008* in);

struct Obj_0019D008 {
    char pad0[0xC];
    void* mC;
    char pad10[0x1C - 0x10];
    Src_0019D008* m1C;
    char pad20[0x30 - 0x20];
    Vec_0019D008 m30;
    Vec_0019D008 m40;
    char pad50[0xB0 - 0x50];
    State_0019D008* mB0;
    void Fn();
};

extern "C" void func_0019D0D0(Obj_0019D008* self);
extern "C" void func_0019D2D0(Obj_0019D008* self);
extern "C" void func_0019D498(Obj_0019D008* self);

void Obj_0019D008::Fn()
{
    mB0->m2C = 0;
    mB0->m28 = 0;
    mB0->m1C = 0;
    m40 = Vec_0019D008(-m1C->m90.x, -m1C->m90.y, -m1C->m90.z, -m1C->m90.w);
    m40.y = 0.0f;
    func_003233B8(&m40, &m40);
    func_0019D0D0(this);
    m30 = m40;
    func_0019D2D0(this);
    func_0019D498(this);
    func_00185578(mC, 0xC4E311FA)->V1();
}
