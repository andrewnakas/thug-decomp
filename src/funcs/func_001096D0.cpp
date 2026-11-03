extern "C" void func_001E8870(void*, int, int*, int);
extern "C" int func_001E87B8(void*, const char*);
extern "C" void func_00109128(void*, int, int);
extern "C" void func_00103F28(const char*, ...);
extern void* D_00388A44;
extern char D_0035AFE0[], D_0035AFF0[], D_0035B028[];

bool func_001096D0(void* params, void* script)
{
    void* fs = D_00388A44;
    if (func_001E87B8(params, D_0035AFE0)) {
        func_00103F28(D_0035AFF0);
        return true;
    }
    int name;
    func_001E8870(params, 0, &name, 1);
    func_00109128(fs, name, func_001E87B8(params, D_0035B028));
    return true;
}
