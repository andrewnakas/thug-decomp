extern char D_00366EA0[];
extern "C" unsigned int func_001F0D78(char* s);
extern "C" bool func_001E8248(void* params, unsigned int name, int* out, int required);
extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" void func_001E66C0(void* p, int v);

extern "C" void func_00206E40(void* self, void* params)
{
    unsigned int name = func_001F0D78(D_00366EA0);
    int v = 0;
    func_001E8248(params, name, &v, 0);
    func_001E66C0(func_001E55B8(0xDFA17D68, 1), v);
}
