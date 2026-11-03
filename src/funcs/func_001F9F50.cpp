extern int D_0039412C;
extern int D_00394130;
extern "C" void func_001F9EC0();
extern "C" void func_001F8E30();

struct SemaParam_001F9F50 {
    int count;
    int max;
    int init;
    int waits;
    unsigned int attr;
    unsigned int option;
};

struct Net_001F9F50 {
    char m_pad[0x2A8];
    int m2A8;
    char m_pad1[0x2B8 - 0x2AC];
    int m2B8;
    char m_pad2[0x2CC - 0x2BC];
    int m2CC;
    char m_pad3[0x2E0 - 0x2D0];
    char m2E0[0x32E0 - 0x2E0];
    char m32E0[0x10];
    int m32F0;
    int m32F4;
    void (*m32F8)();
    char* m32FC;
    int m3300;
    int m3304;
    int m3308;
    int m330C;
};

extern "C" int func_001FA1B0();
extern "C" int func_001FA648(Net_001F9F50*);
extern "C" void func_001FA6A0(Net_001F9F50*, int);
extern "C" int func_00327958(int, int*, int, int);
extern "C" int func_003276D8(int*);
extern "C" int func_00324700(int, void (*)(), int*);
extern "C" int func_0031BCA0(SemaParam_001F9F50*);
extern "C" int func_00106038(char*);
extern "C" void func_0031BAC0(int, Net_001F9F50*);

int func_001F9F50(Net_001F9F50* n)
{
    SemaParam_001F9F50 sp;
    int status;
    int state;
    int x;
    if (!func_001FA1B0() || n->m2CC != 0) {
        if (func_001FA648(n) == 2) {
            n->m2A8 = 1;
        } else if (func_001FA648(n) == 1 || func_001FA648(n) == 3) {
            D_0039412C = 0;
            if (func_00327958(0, &status, 0, 0) || status || func_003276D8(&state)
                || ((unsigned int)(state - 3) >= 2 && func_00324700(10, func_001F9EC0, &x))) {
                func_001FA6A0(n, 7);
                n->m2B8 = 3;
                return 0;
            }
            sp.max = 10;
            sp.init = 1;
            D_00394130 = func_0031BCA0(&sp);
            func_001FA6A0(n, -1);
            n->m3304 = 10;
            n->m32F8 = func_001F8E30;
            n->m32FC = n->m2E0;
            n->m3300 = 0x3000;
            n->m32F0 = 0x150;
            func_00106038(n->m32E0);
            n->m330C = n->m32F4;
            func_0031BAC0(n->m32F4, n);
        }
    }
    return n->m2A8;
}
