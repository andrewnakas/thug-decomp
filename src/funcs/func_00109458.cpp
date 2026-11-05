struct Ctx_00109458 {
    int m0;
    void* m4;
};

extern Ctx_00109458* D_00388A30;
extern int D_00388A34;
extern "C" int func_00108A00(Ctx_00109458* ctx, int a);
extern "C" int func_001085F0(void* p, void* dst, int size);

extern "C" int func_00109458(void* dst, int size, int count, int a)
{
    if (func_00108A00(D_00388A30, a)) {
        D_00388A34 = 1;
        return func_001085F0(D_00388A30->m4, dst, size * count);
    }
    D_00388A34 = 0;
    return 0;
}
