extern "C" unsigned int func_0010FC30();

struct Obj_001AF328 {
    char pad[0x12F4];
    int m12F4;
    char pad4856[0x1300 - 0x12F4 - 4];
    unsigned int m1300;
    unsigned int m1304;
    void Method();
};

void Obj_001AF328::Method()
{
    if (m12F4 && m1304 != 0xFFFFFFFF) {
        unsigned int start = m1300;
        if (func_0010FC30() - start > m1304)
            m12F4 = 0;
    }
}
