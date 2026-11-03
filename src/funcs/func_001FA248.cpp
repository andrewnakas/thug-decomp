extern "C" void func_00331A9C(void* p);

struct Obj_001FA248 {
    char pad[0x1c0];
    int m_sub;
    void Run();
};

void Obj_001FA248::Run()
{
    func_00331A9C(&m_sub);
}
