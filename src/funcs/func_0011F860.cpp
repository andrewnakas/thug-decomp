extern "C" void func_001E7360(void* p);

struct Obj_0011F860 {
    char pad[0x48];
    int m_sub;
    void Run();
};

void Obj_0011F860::Run()
{
    func_001E7360(&m_sub);
}
