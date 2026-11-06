struct C_00270D00;
extern "C" void func_00270D30(C_00270D00* self, int v);

struct C_00270D00 {
    char m_pad[0x1C];
    unsigned int m1C;
    int m20;
    int m24;
    void Run();
};

void C_00270D00::Run()
{
    func_00270D30(this, m1C < 2 ? m24 : m20);
}
