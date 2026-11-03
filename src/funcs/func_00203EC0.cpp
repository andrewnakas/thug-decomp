extern "C" void func_0013B0E8(void* p);

struct Obj_00203EC0 {
    char pad[0x320];
    void* m_p;
    void Run();
};

void Obj_00203EC0::Run()
{
    func_0013B0E8(m_p);
}
