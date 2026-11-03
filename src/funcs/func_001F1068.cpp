struct Heap_001F1068 {
    char pad[0xE4];
    int mE4;
};
extern Heap_001F1068* D_00388A70;
extern void* D_0038C7B0;
extern "C" void* func_0010A638(void* pool, unsigned int size, int a, int b);
extern "C" void func_0010A950(void*, int);
extern "C" void func_0010A9B0(void*);
extern "C" void* func_00187EC0(void*);
extern "C" void func_00187F90(void*, int, int, int, int, int);
extern "C" void func_00189CE0(void*, int, void*);

struct Obj_001F1068 {
    char pad[0xDC];
    void* mDC;
    void Add(int a, int b, int c, int d, int e);
};

void Obj_001F1068::Add(int a, int b, int c, int d, int e)
{
    func_0010A950(D_00388A70, D_00388A70->mE4);
    if (!mDC)
        mDC = func_00187EC0(func_0010A638(D_00388A70, 0x14, 1, 0));
    func_00187F90(mDC, a, b, c, d, e);
    func_00189CE0(D_0038C7B0, a, this);
    func_0010A9B0(D_00388A70);
}
