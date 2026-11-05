struct Inst_002C7488 {
    int m0;
    int m4;
    int m8;
};

extern "C" void func_002BE958(void* p, Inst_002C7488* i, int a);

struct Obj_002C7488 {
    char pad0[8];
    void* m8;
    char padC[0x50 - 0xC];
    Inst_002C7488* m50;
    void Release();
};

void Obj_002C7488::Release()
{
    if (m50) {
        m50->m8 &= ~0x200;
        func_002BE958(m8, m50, 0);
        m50 = 0;
    }
}
