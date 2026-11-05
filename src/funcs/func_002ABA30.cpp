extern "C" void func_00202688(void* p, int v);

struct Obj_002ABA30 {
    signed char* m0;
    char pad4[0x14 - 4];
    void* m14;
    int Run();
};

int Obj_002ABA30::Run()
{
    func_00202688(m14, *m0 * 1000);
    return 1;
}
