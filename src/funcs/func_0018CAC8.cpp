extern "C" void func_0013F010(void* o);

struct Obj_0018CAC8 {
    char pad[0x260];
    void* m_260;
    void Run();
};

void Obj_0018CAC8::Run()
{
    if (m_260)
        func_0013F010(m_260);
}
