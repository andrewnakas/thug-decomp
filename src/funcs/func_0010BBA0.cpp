struct Heap_0010BBA0 {
    char pad0[0xDC];
    int mDC;
};

extern Heap_0010BBA0* D_00388A70;
extern char D_004647E8[];
extern "C" void* func_001047C0(int size, void* mem);
extern "C" Heap_0010BBA0* func_0010A420(void* p);
extern "C" void func_0010A950(Heap_0010BBA0* h, int a);

extern "C" void func_0010BBA0()
{
    if (!D_00388A70) {
        D_00388A70 = func_0010A420(func_001047C0(0x400, D_004647E8));
        func_0010A950(D_00388A70, D_00388A70->mDC);
    }
}
