extern "C" void func_002294C0(void* p);

struct Obj_001D1E18 {
    char m_pad[0x24];
    void* m_24;
    int Run();
};

int Obj_001D1E18::Run()
{
    func_002294C0(m_24);
    return 0;
}
