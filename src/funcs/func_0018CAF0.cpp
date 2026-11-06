extern "C" void* func_0013D8A8(void* p);
extern "C" void func_00137CF0(void* p);
struct Obj_0018CAF0 {
    char pad[0x260];
    void* m260;
    void Run();
};

void Obj_0018CAF0::Run()
{
    func_00137CF0(func_0013D8A8(m260));
}
