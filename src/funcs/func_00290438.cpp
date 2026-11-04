struct Sub_00290438 {
    char pad0[0x50];
    char m50[0x20];
    char m70[0x1C8];
    int m238;
};

struct St_00290438 {
    char pad[0x1C];
    int m1C;
};

struct Obj_00290438 {
    char pad0[0xC];
    Sub_00290438* mC;
    char pad10[0x1C - 0x10];
    St_00290438* m1C;
};

extern "C" void func_00206828(Sub_00290438* s);
extern "C" void func_002041F0(Sub_00290438* s, char* a, char* b);

extern "C" void func_00290438(Obj_00290438* o)
{
    if (o->mC->m238 && o->m1C->m1C != 4)
        func_00206828(o->mC);
    func_002041F0(o->mC, o->mC->m50, o->mC->m70);
}
