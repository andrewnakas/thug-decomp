extern "C" void func_00200F28(void* a, void* b);

struct Obj_001FD388 {
    char pad0[0x10];
    void* m10;
    void* m14;
    int Run();
};

int Obj_001FD388::Run()
{
    func_00200F28(m10, m14);
    return 2;
}
