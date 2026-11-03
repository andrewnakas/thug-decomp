struct Heap_00105638 {
    char pad[0xD8];
    int m_D8;
};

extern Heap_00105638* D_00388A70;
extern "C" void func_0010A950(Heap_00105638*, int);
extern "C" void* func_0010A638(Heap_00105638*, int, int, int);
extern "C" void func_0010A9B0(Heap_00105638*);

extern void* D_00393EA0;
extern void* D_00393EA4;
extern int* D_00393EA8;
extern int* D_00393EAC;

void func_00105638()
{
    func_0010A950(D_00388A70, D_00388A70->m_D8);
    D_00393EA0 = func_0010A638(D_00388A70, 0x1011, 1, 0);
    D_00393EA4 = func_0010A638(D_00388A70, 0x4004, 1, 0);
    D_00393EA8 = (int*)func_0010A638(D_00388A70, 0x4404, 1, 0);
    D_00393EAC = (int*)func_0010A638(D_00388A70, 0x4004, 1, 0);
    func_0010A9B0(D_00388A70);
    for (int i = 0x1001; i < 0x1101; i++)
        D_00393EA8[i] = 0x1000;
    for (int i = 0; i < 0x1000; i++)
        D_00393EAC[i] = 0x1000;
}
