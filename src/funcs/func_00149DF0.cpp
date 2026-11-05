extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00146C90(void* mem, int id);
extern "C" void func_00138618(void* s, const char* name, int a, int b);
extern void* D_00388A70;

extern "C" void* func_00149DF0(void* self, const char* name, int a, int b)
{
    void* s = func_00146C90(func_0010A638(D_00388A70, 0x30, 1, 0), 0);
    func_00138618(s, name, a, b);
    return s;
}
