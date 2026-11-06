extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_00149AB0(void* mem, int id);
extern void* D_00388A70;

extern "C" void* func_0014A0E0(int id)
{
    return func_00149AB0(func_0010A638(D_00388A70, 0x18, 1, 0), id);
}
