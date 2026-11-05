extern void* D_0038F9C4;
extern int D_0038F9C8;
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void func_001E9D70(void* dst, void* src);

void Store_00224260(void* params, int value)
{
    if (D_0038F9C4) {
        func_001E6AE8(D_0038F9C4, 3);
        D_0038F9C4 = 0;
    }
    D_0038F9C4 = func_001E6978(func_001190D0(8));
    func_001E9D70(D_0038F9C4, params);
    D_0038F9C8 = value;
}
