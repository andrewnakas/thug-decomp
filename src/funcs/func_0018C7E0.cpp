extern "C" void func_0013D910(void* o);

struct Obj_0018C7E0 {
    char pad[0x260];
    void* m_260;
    void Run();
};

void Obj_0018C7E0::Run()
{
    if (m_260)
        func_0013D910(m_260);
}
