extern "C" void func_00172960(void* p);

struct Obj14E550 {
    char m_pad[0x18];
    void* m18;
    int Run();
};

int Obj14E550::Run()
{
    if (m18) {
        func_00172960(m18);
        return 1;
    }
    return 0;
}
