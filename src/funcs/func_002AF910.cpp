extern void* D_0038FC78;
extern "C" void func_002A8568(void* p);
extern "C" bool func_00215778(int a, int b);
extern "C" void* func_0022E358(void* p);
extern "C" unsigned int func_0024F938(void* p);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

struct Obj_002AF910 {
    char pad[0x1C];
    void* m1C;
    bool Run();
};

bool Obj_002AF910::Run()
{
    void* g = D_0038FC78;
    func_002A8568(m1C);
    if (func_00215778(0, 0)) {
        if (func_0024F938(func_0022E358(g)) == 0xEC200EAA)
            func_001F0210(0xFCE4F72D, 0, 0, 0, 0);
    }
    return true;
}
