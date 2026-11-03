extern "C" void func_002629A8(void* p);

struct Obj_0022E3C8 {
    char pad[0x80];
    void* m_p;
    void Run();
};

void Obj_0022E3C8::Run()
{
    func_002629A8(m_p);
}
