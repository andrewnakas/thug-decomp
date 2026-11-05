extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00146C90(void* mem, int id);
extern "C" void func_00138700(void* s, int a, int b, int c, int d, int e);
extern void* D_00388A70;

extern "C" void* func_00149E70(void* self, int a, int b, int c, int d, int e)
{
    void* s = func_00146C90(func_0010A638(D_00388A70, 0x30, 1, 0), 0);
    func_00138700(s, a, b, c, d, e);
    return s;
}
