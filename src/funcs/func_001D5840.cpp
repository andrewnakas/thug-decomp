extern "C" void func_001D87F8(void* p);

struct Obj_001D5840 {
    char m_pad[0x8];
    void* m_8;
    void Run();
};

void Obj_001D5840::Run()
{
    func_001D87F8(m_8);
}
