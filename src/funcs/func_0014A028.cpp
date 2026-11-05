extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00149AB0(void* mem, int id);
extern "C" int func_00149D10(void* t, const char* name, int a, int b, int flag, int c, int d, int e);
extern void* D_00388A70;

extern "C" void* func_0014A028(int id, int a, int b, int flag, int c, int d, int e)
{
    void* t = func_00149AB0(func_0010A638(D_00388A70, 0x18, 1, 0), id);
    func_00149D10(t, 0, a, b, flag, c, d, e);
    return t;
}
