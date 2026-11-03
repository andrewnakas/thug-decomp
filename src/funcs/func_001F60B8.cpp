extern "C" int func_0031BCE0(int);
extern "C" void func_0031BCC0(int);
extern "C" void func_001F5AF8(int);
extern "C" void func_001F5A88(int);

#define REG_001F60B8(a) (*(volatile int*)(a))

struct Ctx_001F60B8 {
    int m_pad[7];
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    int m44;
};

int func_001F60B8(Ctx_001F60B8* c)
{
    func_0031BCE0(c->m40);
    c->m44 = 0;
    func_001F5AF8(5);
    c->m1C = REG_001F60B8(0x1000B410);
    c->m20 = REG_001F60B8(0x1000B430);
    c->m24 = REG_001F60B8(0x1000B420);
    c->m28 = REG_001F60B8(0x1000B400);
    while (REG_001F60B8(0x10002010) & 0xF0)
        ;
    func_001F5A88(0);
    c->m2C = REG_001F60B8(0x1000B010);
    c->m30 = REG_001F60B8(0x1000B020);
    c->m34 = REG_001F60B8(0x1000B000);
    c->m38 = REG_001F60B8(0x10002020);
    c->m3C = REG_001F60B8(0x10002010);
    func_0031BCC0(c->m40);
    return 1;
}
