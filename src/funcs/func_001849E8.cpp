struct Heap_001849E8 {
    char pad0[0xE4];
    int mE4;
};
extern Heap_001849E8* D_00388A70;
extern "C" void func_0010A950(Heap_001849E8* heap, int v);
extern "C" void func_0010A9B0(Heap_001849E8* heap);
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);

struct Obj_001849E8 {
    char pad0[0x24];
    void* m24;
    void Fn();
};

void Obj_001849E8::Fn()
{
    if (m24)
        return;
    func_0010A950(D_00388A70, D_00388A70->mE4);
    m24 = func_001E6978(func_001190D0(8));
    func_0010A9B0(D_00388A70);
}
