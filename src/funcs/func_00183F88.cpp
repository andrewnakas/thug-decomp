extern "C" void func_001F1138(void* p);
struct Obj_00183F88 {
    char pad[0x14];
    void* m14;
    void Run();
};

void Obj_00183F88::Run()
{
    if (m14) {
        func_001F1138(m14);
    }
}
