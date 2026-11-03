extern "C" void func_00331A9C(void* p);

struct Obj_001FA228 {
    char pad[0x1a0];
    int m_sub;
    void Run();
};

void Obj_001FA228::Run()
{
    func_00331A9C(&m_sub);
}
