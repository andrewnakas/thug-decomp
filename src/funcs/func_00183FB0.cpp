extern "C" void func_001E7200(void* p, int a, int b);

struct Comp183FB0 {
    char m_pad[0x24];
    void* m24;
    void Set(int a, int b);
};

extern "C" void func_001849E8(Comp183FB0* c, int a, int b);

void Comp183FB0::Set(int a, int b)
{
    func_001849E8(this, a, b);
    func_001E7200(m24, a, b);
}
