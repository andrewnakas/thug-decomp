extern "C" void func_001E6AC8(void* p);

struct Obj_00202F58 {
    char pad[0x4];
    int m_sub;
    void Run();
};

void Obj_00202F58::Run()
{
    func_001E6AC8(&m_sub);
}
