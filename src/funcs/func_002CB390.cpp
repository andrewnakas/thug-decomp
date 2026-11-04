struct Color_002CB390 {
    unsigned char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    signed char m4;
    signed char m5;
};

struct Obj_002CB390_S {
    char pad0[0x352C];
    Color_002CB390 m352C;
};

struct Obj_002CB390_R {
    char pad0[0x18];
    void* m18;
};

extern "C" Obj_002CB390_S* func_002C0368(void* p);
extern "C" void func_001E7200(void* p, unsigned int key, int v);

int func_002CB390(void* p, Obj_002CB390_R* r)
{
    Color_002CB390 c = func_002C0368(p)->m352C;
    func_001E7200(r->m18, 0x7323E97C, c.m0);
    func_001E7200(r->m18, 0x9D2D8850, c.m2);
    func_001E7200(r->m18, 0xE39CF4ED, c.m3);
    func_001E7200(r->m18, 0x69F93D01, (unsigned char)c.m5);
    return 1;
}
