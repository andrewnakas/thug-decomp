typedef int qword __attribute__((mode(TI)));

struct C_001CCE30;
extern "C" void func_001BF130(C_001CCE30* self, int a);
extern "C" void func_001C4030(C_001CCE30* self, qword* a, qword* b);

struct C_001CCE30 {
    char m_pad[0x40];
    qword m40;
    qword m50;
    qword m60;
    char m70[0xB00];
    qword mB70;
    void Run();
};

void C_001CCE30::Run()
{
    func_001BF130(this, 1);
    mB70 = m60;
    func_001C4030(this, &m40, &m50);
}
