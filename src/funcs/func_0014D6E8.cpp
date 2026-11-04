extern "C" void func_00170630(void* p);

struct Obj0014D6E8 {
    char pad[0x20];
    void* m_p;
    void Run();
};

void Obj0014D6E8::Run()
{
    func_00170630(m_p);
}
