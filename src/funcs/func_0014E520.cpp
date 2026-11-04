extern "C" void func_00172940(void* p);

struct Obj14E520 {
    char m_pad[0x18];
    void* m18;
    int Run();
};

int Obj14E520::Run()
{
    if (m18) {
        func_00172940(m18);
        return 1;
    }
    return 0;
}
