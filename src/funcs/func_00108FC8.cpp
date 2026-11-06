extern "C" void* func_00104760(int size, int a, int b);
extern "C" void* func_001087A8(void* p);
extern void* D_00388A44;
extern int D_00388A48;

extern "C" void* func_00108FC8(int create)
{
    if (!D_00388A44 && create) {
        D_00388A44 = func_001087A8(func_00104760(0x240, 0, 1));
    }
    D_00388A48++;
    return D_00388A44;
}
