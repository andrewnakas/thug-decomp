extern void* D_00388EFC;
extern "C" void func_001DFF88(int v);
extern "C" void func_001E0038(int v);
extern "C" void* func_00112FB8(void* a, int b, int c);
extern "C" int func_00113140(void* a);

int Load_00227658()
{
    int r = 0;
    func_001DFF88(1);
    func_001E0038(1);
    void* p = func_00112FB8(D_00388EFC, 0, 0);
    if (p) {
        r = func_00113140(p);
    }
    func_001DFF88(-1);
    func_001E0038(-1);
    return r;
}
