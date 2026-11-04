struct Mgr_00139EB8 {
    int m0;
    char m4[4];
};

extern "C" int func_001E84E8(void* params, char* name, int* out, int req);
extern "C" Mgr_00139EB8* func_0022E368(void* o, int a);
extern "C" void* func_001200E0(void* p);
extern "C" int func_00123430(void* q);
extern "C" int func_00123438(void* q);
extern "C" void* func_00139008(void* o, int a, int b, int c, int d, int e, int f);

extern char D_0035DFF0[];
extern void* D_0038FC78;
extern void* D_00393EF4;

bool func_00139EB8(void* params)
{
    int v;
    func_001E84E8(params, D_0035DFF0, &v, 1);
    void* q = func_001200E0(func_0022E368(D_0038FC78, 0)->m4);
    int a = func_00123430(q);
    int b = func_00123438(q);
    return func_00139008(D_00393EF4, a, b, v, 1, 1, 1) != 0;
}
