extern "C" void func_00331A9C(void* p);

struct Obj_00294EA8 {
    char pad[0x4];
    int m_sub;
    void Run();
};

void Obj_00294EA8::Run()
{
    func_00331A9C(&m_sub);
}
