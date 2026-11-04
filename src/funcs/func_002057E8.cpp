extern "C" void* func_00185578(void* self, unsigned int crc);
extern "C" int func_0019FAB8(int a);
extern "C" int func_001B7338(void* a);
extern "C" int func_001EE4D8(int a, int b);
extern "C" int func_002713D8(int a);
extern "C" int func_00291340(void* a);

struct Obj_002057E8 {
    char pad0[0x14];
    int m_14;
    char pad18[0x2B0 - 0x18];
    int m_2B0;
    char pad2B4[0x2D0 - 0x2B4];
    int m_2D0;
    char pad2D4[0x31C - 0x2D4];
    int m_31C;
    void Run();
};

void Obj_002057E8::Run()
{
    if (m_31C) {
        func_002713D8(m_2D0);
        func_00291340(func_00185578(this, 0x589E5FB3));
    }
    func_001B7338(func_00185578(this, 0xF27A294D));
    func_0019FAB8(m_2B0);
    if (m_14) {
        func_001EE4D8(m_14, 3);
        m_14 = 0;
    }
}
