struct Mgr_001093F8 {
    int m0;
    void* m4;
};

extern Mgr_001093F8* D_00388A30;
extern int D_00388A34;
extern "C" int func_00108A00(Mgr_001093F8* mgr, int a);
extern "C" void func_001086A8(void* p, int b);

extern "C" int func_001093F8(int a, int b)
{
    if (func_00108A00(D_00388A30, a)) {
        func_001086A8(D_00388A30->m4, b);
        D_00388A34 = 1;
        return 0;
    }
    D_00388A34 = 0;
    return 0;
}
