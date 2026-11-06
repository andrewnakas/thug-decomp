typedef int qword_001BF0D8 __attribute__((mode(TI)));

struct Vec_001BF0D8 {
    union {
        qword_001BF0D8 q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Obj_001BF0D8;
extern "C" void func_001BF130(Obj_001BF0D8* o, int a);
extern "C" void func_003233B8(Vec_001BF0D8* out, Vec_001BF0D8* in);
extern "C" void func_001C4030(Obj_001BF0D8* o, Vec_001BF0D8* pos, float* y);

struct Model_001BF0D8 {
    char pad[0xB0];
    Vec_001BF0D8 mB0;
};

struct Obj_001BF0D8 {
    char pad[0xC];
    Model_001BF0D8* mC;
    char pad10[0xB70 - 0x10];
    Vec_001BF0D8 mB70;
    void Method();
};

void Obj_001BF0D8::Method()
{
    func_001BF130(this, 1);
    mB70 = mC->mB0;
    mB70.y = 0.0f;
    func_003233B8(&mB70, &mB70);
    func_001C4030(this, &mC->mB0, &mC->mB0.y);
}
