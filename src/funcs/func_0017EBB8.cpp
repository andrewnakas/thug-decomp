class Obj_0017EBB8 {
public:
    int m_0;
    unsigned int m_flags;
    int Run();
};

extern "C" void func_0017B4D8();

int Obj_0017EBB8::Run()
{
    m_flags &= ~2;
    func_0017B4D8();
    return 1;
}
