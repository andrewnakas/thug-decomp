extern "C" void func_001E7360(void* p, int a, int b);

struct Comp184000 {
    char m_pad[0x24];
    void* m24;
    void Set(int a, int b);
};

extern "C" void func_001849E8(Comp184000* c, int a, int b);

void Comp184000::Set(int a, int b)
{
    func_001849E8(this, a, b);
    func_001E7360(m24, a, b);
}
