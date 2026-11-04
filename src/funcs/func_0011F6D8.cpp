extern "C" void func_001E6B90(void* p);

struct Obj_0011F6D8 {
    char pad[0x48];
    int m_sub;
    void Run();
};

void Obj_0011F6D8::Run()
{
    func_001E6B90(&m_sub);
}
