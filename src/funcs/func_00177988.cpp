struct Heap_00177988 {
    char pad0[0xD8];
    int mD8;
};
extern Heap_00177988* D_00388A70;
extern int* D_0038BF84;
extern "C" void func_0010A950(Heap_00177988* heap, int v);
extern "C" void func_0010A9B0(Heap_00177988* heap);
extern "C" void* func_0010BDE0(int size);

void func_00177988()
{
    func_0010A950(D_00388A70, D_00388A70->mD8);
    D_0038BF84 = (int*)func_0010BDE0(40000);
    for (int i = 0; i < 10000; i++)
        D_0038BF84[i] = 0;
    func_0010A9B0(D_00388A70);
}
