extern void* D_00388A70;
extern char D_00370F08[];
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0010ACE0(void* pool, unsigned int name);
extern "C" void func_001826C8(void* p);

extern "C" bool func_00219240(void* params, void* script)
{
    void* pool = D_00388A70;
    unsigned int name = func_001F0D78(D_00370F08);
    if (params)
        func_001E8398(params, 0, &name, 0);
    void* p = func_0010ACE0(pool, name);
    if (p)
        func_001826C8(p);
    return true;
}
