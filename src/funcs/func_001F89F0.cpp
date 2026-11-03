extern "C" void func_003250C0(int, int*);
extern "C" int func_003244A8(void**);
extern "C" int func_00327BE0(int, int, int*, int);
extern "C" int func_00327358(char*);
extern char D_003666B0[];

struct Net_001F89F0;
extern "C" int func_001F8590(Net_001F89F0*);
extern "C" int func_001F87E0(Net_001F89F0*);
extern "C" int func_001F85D8(Net_001F89F0*);
extern "C" int func_001FA648(Net_001F89F0*);
extern "C" void func_001FA658(Net_001F89F0*, int);

struct Slot_001F89F0 {
    int m[4];
};

struct Net_001F89F0 {
    char m_pad[0x150];
    Slot_001F89F0 m150[3];
    char m_pad2[0x2CC - 0x180];
    int m2CC;
};

int func_001F89F0(Net_001F89F0* n)
{
    void* slots[3];
    int status;
    int one;
    func_003250C0(0, &status);
    if (status == 1 && !func_001F8590(n))
        return 0;
    if (func_001FA648(n) == 2 && !func_001F87E0(n))
        return 0;
    for (int i = 2; i >= 0; i--)
        slots[i] = &n->m150[i];
    if (func_003244A8(slots)) {
        func_001FA658(n, 1);
        return 0;
    }
    if (func_001FA648(n) == 3) {
        one = 1;
        func_00327BE0(0, 7, &one, 4);
    }
    if ((func_001FA648(n) == 1 || func_001FA648(n) == 3) && func_00327358(D_003666B0)) {
        func_001FA658(n, 4);
        return 0;
    }
    if (!func_001F85D8(n))
        return 0;
    n->m2CC = 0;
    return 1;
}
