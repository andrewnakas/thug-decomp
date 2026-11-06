extern "C" void func_00184920(void* obj, unsigned int name, float f, void* params);

struct Obj_001B0E78 {
    char pad[0xC];
    void* mC;
    char pad10[0x13FC - 0x10];
    int m13FC;
    void Method();
};

void Obj_001B0E78::Method()
{
    if (++m13FC >= 4)
        func_00184920(mC, 0x94182A08, 0.0f, 0);
}
