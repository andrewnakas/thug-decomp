extern char D_003E0AA0[];
extern int D_0038BC1C;
extern "C" int func_0016C5D0(const void* a, const void* b);
extern "C" void func_00334658(void* base, int n, int size, int (*cmp)(const void*, const void*));

extern "C" void func_0016C618()
{
    func_00334658(D_003E0AA0, D_0038BC1C, 0x70, func_0016C5D0);
}
