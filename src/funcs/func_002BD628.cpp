struct Box_002BD628 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Cell_002BD628 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Mgr_002BD628;
struct Obj_002BD628;

extern char D_0037A560[];
extern "C" void func_002C42E8(Obj_002BD628* o);
extern "C" void func_002C3330(Obj_002BD628* o);
extern "C" void func_002C32A0(Obj_002BD628* o, int a);
extern "C" void func_002B7DB0(Mgr_002BD628* m, int a);
extern "C" void func_002BD2B0(Obj_002BD628* o, char* s);
extern "C" void func_002C38C0(Obj_002BD628* o);
extern "C" int func_002BDDA8(Obj_002BD628* o, Box_002BD628* b);
extern "C" void func_002C2288(Obj_002BD628* o, int a, int b);
extern "C" void* func_0029C320();
extern "C" void func_0029A6F8(void* p);

struct Obj_002BD628 {
    Mgr_002BD628* m0;
    int m4;
    int m8;
    char padC[0x352C - 0xC];
    Box_002BD628 m352C;
    char pad3532[0x3538 - 0x3532];
    Cell_002BD628** m3538;
    char pad353C[0x6A64 - 0x353C];
    int m6A64;
    void Rebuild(int full);
};

void Obj_002BD628::Rebuild(int full)
{
    func_002C42E8(this);
    if (!(m6A64 & 5) && m8) func_002C3330(this);
    func_002C32A0(this, 0);
    func_002B7DB0(m0, 0);
    if (full || !(m6A64 & 2)) {
        for (int z = 0; z < 0x3A; z++) {
            for (int x = 0; x < 0x3A; x++) {
                m3538[x][z].m0 = 0;
                m3538[x][z].m4 = 0;
                m3538[x][z].m8 = 0;
                m3538[x][z].mC = 0;
            }
        }
        func_002C3330(this);
        full = 1;
        func_002BD2B0(this, D_0037A560);
        m6A64 &= ~8;
    } else {
        func_002C38C0(this);
    }
    Box_002BD628 b = m352C;
    func_002BDDA8(this, &b);
    func_002C2288(this, full, 0);
    func_002B7DB0(m0, 1);
    m8 = 1;
    if (full) m6A64 |= 1;
    func_0029A6F8(func_0029C320());
}
