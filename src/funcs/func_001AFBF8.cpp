struct Obj_001AFBF8;
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" float func_001AFC58(Obj_001AFBF8* o);
extern "C" void func_001A18C8(void* comp, float f, int a, int b);

struct Obj_001AFBF8 {
    char pad[0xC];
    void* mC;
    char pad10[0x1378 - 0x10];
    int m1378;
    void Method();
};

void Obj_001AFBF8::Method()
{
    if (m1378) {
        void* comp = func_00185578(mC, 0x72AD7B23);
        func_001A18C8(comp, func_001AFC58(this), 1, 0);
    }
}
