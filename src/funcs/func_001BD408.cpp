extern "C" void func_00142350(void* p);

struct Obj001BD408 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj001BD408::Run()
{
    func_00142350(m_p);
}
