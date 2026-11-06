extern "C" void func_001818E0(void* p);

class Obj_00149DD0 {
public:
    char pad[0x14];
    void* m_14;
    int Run();
};

int Obj_00149DD0::Run()
{
    func_001818E0(m_14);
    return 0;
}
