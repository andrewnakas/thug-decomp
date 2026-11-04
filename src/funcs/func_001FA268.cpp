extern "C" void func_00331A9C(void* p);

struct Obj_001FA268 {
    char pad[0x210];
    int m_sub;
    void Run();
};

void Obj_001FA268::Run()
{
    func_00331A9C(&m_sub);
}
