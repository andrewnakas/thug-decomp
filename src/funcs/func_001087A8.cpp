extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010A048(void* mem, int n);

struct Mgr_001087A8;
extern Mgr_001087A8* D_00388A30;

struct Mgr_001087A8 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    void* m14;
    char pad18[0x23C - 0x18];
    int m23C;
    Mgr_001087A8();
};

Mgr_001087A8::Mgr_001087A8()
{
    m14 = func_0010A048(func_0010A638(D_00388A70, 0x18, 1, 0), 4);
    D_00388A30 = this;
    m8 = 0;
    mC = 0;
    m10 = 0;
    m23C = 0;
}
