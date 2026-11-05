extern "C" void func_002AB228(void* a, int b);
extern "C" void func_002A4DD0(void* p);

struct Obj_002ACD00 {
    char pad0[0x1C];
    void* m1C;
    bool Run();
};

bool Obj_002ACD00::Run()
{
    void* p = m1C;
    func_002AB228(0, 0);
    func_002A4DD0(p);
    return true;
}
