extern "C" void func_001DA7C0(void* p);

struct Obj_001D66B8 {
    char m_pad[0x8];
    void* m_8;
    void Run();
};

void Obj_001D66B8::Run()
{
    func_001DA7C0(m_8);
}
