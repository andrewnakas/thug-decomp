extern "C" void func_001048F0(void* p);

struct Obj_0022C480 {
    char pad[0x18];
    void* m_p;
    void Run();
};

void Obj_0022C480::Run()
{
    func_001048F0(m_p);
}
