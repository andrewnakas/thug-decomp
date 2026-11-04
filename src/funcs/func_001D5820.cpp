extern "C" void func_001D84E0(void* p);

struct Obj_001D5820 {
    char m_pad[0x8];
    void* m_8;
    void Run();
};

void Obj_001D5820::Run()
{
    func_001D84E0(m_8);
}
