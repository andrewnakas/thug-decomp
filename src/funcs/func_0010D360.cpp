extern void* D_00388A70;
extern void* D_00388C28;
extern char D_0035B710[];
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void* func_0010D490(int a);
extern "C" void* func_0010D190(void* p, void* a, int b, char* name);

extern "C" void func_0010D360(int exists, int arg)
{
    if (!exists) {
        void* p = func_0010A638(D_00388A70, 0x5C, 1, 0);
        D_00388C28 = func_0010D190(p, func_0010D490(0), arg, D_0035B710);
    }
}
