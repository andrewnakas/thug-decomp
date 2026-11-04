struct Obj_002D4118 {
    char pad0[8];
    int m8;
    int mC;
    int m10;
};

struct Thing_002D4118 {
    int m0;
    char m4[4];
};

extern void* D_0038FC78;
extern "C" Thing_002D4118* func_0022E368(void* p, int v);
extern "C" void* func_001200E0(void* p);
extern "C" void func_00122ED8(void* p, void* a, int b);
extern "C" void func_00123428(void* p, int v);
extern "C" void func_001F0210(unsigned int key, int a, int b, int c, int d);

bool Cmd_002D4118(void* a0, int v, void* p, int a3, Obj_002D4118* o)
{
    o->m8 = 100;
    if (!v) {
        o->mC = 1;
        o->m10 = 0;
        void* q = func_001200E0(func_0022E368(D_0038FC78, 0)->m4);
        func_00122ED8(q, p, 0);
        func_00123428(q, 1);
        func_001F0210(0x808008EA, 0, 0, 0, 0);
    } else {
        o->m10 = v;
        o->mC = 2;
    }
    return true;
}
