extern "C" void func_00107E18(void* p);

struct Obj001BAC48 {
    char pad[0x38];
    void* m_p;
    void Run();
};

void Obj001BAC48::Run()
{
    func_00107E18(m_p);
}
