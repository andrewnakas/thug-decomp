extern "C" void func_0025A3A8(void* p);
extern "C" void func_0025A4B0(void* p, void* pos, void* mat);

struct Model_001A96B8 {
    char pad[0x50];
    float m50;
    float m54;
    char pad58[0x18];
    char m70[0x40];
};

struct Obj_001A96B8 {
    char pad[0xC];
    Model_001A96B8* mC;
    char pad10[0x220 - 0x10];
    void* m220;
    int m224;
    void Method();
};

void Obj_001A96B8::Method()
{
    func_0025A3A8(m220);
    Model_001A96B8* m = mC;
    float y = m->m54;
    func_0025A4B0(m220, &m->m50, m->m70);
    if (m224)
        mC->m54 = y;
}
