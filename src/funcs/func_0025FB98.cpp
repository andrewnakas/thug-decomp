extern "C" void func_0013B040(int a, void* b);

struct Obj_0025FB98 {
    char m_pad[0x60];
    int m_data[4];
    void Run();
};

void Obj_0025FB98::Run()
{
    func_0013B040(0, m_data);
}
