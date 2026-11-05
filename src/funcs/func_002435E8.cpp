extern "C" void* func_00240850();
extern "C" void* func_0023BB00(void* a, void* b, int c);
extern "C" void func_0024EBC0(void* a);

extern "C" int func_002435E8(void* a)
{
    func_0024EBC0(func_0023BB00(func_00240850(), a, 1));
    return 1;
}
