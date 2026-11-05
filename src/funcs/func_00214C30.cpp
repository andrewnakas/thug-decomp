extern void* D_00390828;
extern "C" void func_00253F60(void* a, int b);
extern "C" void func_001F04D8(void* a);

extern "C" int func_00214C30(void* params, void* script)
{
    func_00253F60(D_00390828, 1);
    func_001F04D8(script);
    return 1;
}
