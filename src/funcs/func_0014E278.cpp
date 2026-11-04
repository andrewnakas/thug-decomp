extern "C" void func_00170A28(void* p);

struct Obj0014E278 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj0014E278::Run()
{
    func_00170A28(m_p);
}
