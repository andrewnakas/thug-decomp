extern void* D_00392068;
extern char D_00370AF0[];
extern "C" void func_002A78A8(void* o);
extern "C" int func_002A78C0(void* o);
extern "C" void func_001F0370(void* name, int a, int b, int c);

bool func_00215920(void* params, void* script)
{
    void* o = D_00392068;
    func_002A78A8(o);
    if (!func_002A78C0(o))
        func_001F0370(D_00370AF0, 0, 0, 0);
    return true;
}
