extern "C" void func_00103930(void* anim, void* mat, float t);

struct Model_001A8360 {
    char pad[0x70];
    char m70[0x40];
};

struct Obj_001A8360 {
    char pad[0xC];
    Model_001A8360* mC;
    char pad10[0xC];
    int m1C;
    char pad20[0x1F4 - 0x20];
    float m1F4;
    float m1F8;
    void* m1FC;
    char pad200[0x210 - 0x200];
    float m210;
    void Method();
};

void Obj_001A8360::Method()
{
    float t;
    m1F8 += m210;
    if (m1F4 == 0.0f || m1F4 <= m1F8) {
        m1C &= ~0x20;
        t = 1.0f;
    } else {
        t = m1F8 / m1F4;
    }
    func_00103930(m1FC, mC->m70, t);
}
