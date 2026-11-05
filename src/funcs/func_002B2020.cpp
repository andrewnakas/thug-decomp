extern "C" unsigned int func_0010FC30();

struct Obj_002B2020 {
    char pad[0x14C];
    int m14C;
    char pad150[0x158 - 0x150];
    unsigned int m158;
    void Mark();
};

void Obj_002B2020::Mark()
{
    m158 = func_0010FC30();
    m14C |= 2;
}
