extern "C" void func_001D8D78(void* p);

struct Obj_001D66D8 {
    char m_pad[0x8];
    void* m_8;
    void Run();
};

void Obj_001D66D8::Run()
{
    func_001D8D78(m_8);
}
