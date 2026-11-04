struct Obj_002D4040 {
    char pad0[8];
    int m8;
    int mC;
    int m10;
    char pad14[0x378 - 0x14];
    unsigned int m378;
};

extern "C" void func_00224260(void* p, unsigned int key);

bool Cmd_002D4040(void* a0, int v, void* p, int a3, Obj_002D4040* o)
{
    o->m8 = 100;
    if (!v) {
        o->mC = 1;
        unsigned int k = 0;
        switch (o->m378) {
        case 0x5BE5569F:
            k = 0x3BF882CC;
            break;
        case 0x07364EA1:
            k = 0xB010F357;
            break;
        case 0x38DBE1D0:
            k = 0x62896EDF;
            break;
        case 0x1E26FD3E:
            k = 0x61A1BC57;
            break;
        }
        func_00224260(p, k);
        o->m10 = 0;
    } else {
        o->m10 = v;
        o->mC = 2;
    }
    return true;
}
