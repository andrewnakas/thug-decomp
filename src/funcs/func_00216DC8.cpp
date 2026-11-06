extern void* D_0038EB78;
extern char D_0038F648[];
extern "C" int func_001FA648(void* p);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" unsigned int func_001F0D78(const char* s);

extern "C" int func_00216DC8(void* params, void* script)
{
    unsigned int name = 0;
    if (func_001FA648(D_0038EB78) != 1)
        return 1;
    func_001E8398(params, 0, &name, 0);
    if (name == func_001F0D78(D_0038F648))
        return 0;
    return 1;
}
