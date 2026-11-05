struct Ctx_001094F8 {
    int m0;
    void* m4;
};

extern Ctx_001094F8* D_00388A30;
extern int D_00388A34;
extern "C" int func_00108A00(Ctx_001094F8* ctx, int a);
extern "C" int func_00108708(void* p, int offset, int whence);

extern "C" int func_001094F8(int a, int offset, int whence)
{
    if (func_00108A00(D_00388A30, a)) {
        D_00388A34 = 1;
        return func_00108708(D_00388A30->m4, offset, whence);
    }
    D_00388A34 = 0;
    return 0;
}
