extern "C" void func_001E6B30(void* p);

struct Obj_00240790 {
    char pad[0x54];
    void* m_p;
    void Run();
};

void Obj_00240790::Run()
{
    func_001E6B30(m_p);
}
