extern "C" void func_00239158(void* p, int a, float f);
extern "C" void func_00239178(void* p, int a, float f);

struct Sub_00260640 {
    char pad[0x1C];
    void* m1C;
};

struct Obj_00260640 {
    char pad[0xC];
    Sub_00260640* mC;
    char pad10[0x40];
    int m50;
    int m54;
    void Fn();
};

void Obj_00260640::Fn()
{
    if (mC->m1C) {
        func_00239158(mC->m1C, 0, 0.0f);
        func_00239178(mC->m1C, 0, 0.0f);
    }
    m50 = 0;
    m54 = 0;
}
