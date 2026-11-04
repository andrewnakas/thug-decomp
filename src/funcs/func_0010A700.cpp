extern "C" void func_0010A3D0(int);
extern "C" void func_0010A3F8(int);
extern "C" void func_0010C390(void*);
extern int D_00393EB0;

class Heap_0010A700 {
public:
    char pad[0x80];
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void* AllocHigh(int size, int align);
};

struct Mem_0010A700 {
    char pad[0x8C];
    Heap_0010A700** m_stack;
    void* Alloc(int size, int align, Heap_0010A700* heap);
};

void* Mem_0010A700::Alloc(int size, int align, Heap_0010A700* heap)
{
    func_0010A3D0(D_00393EB0);
    if (!heap)
        heap = *m_stack;
    void* p = heap->AllocHigh(size, align);
    if (p)
        func_0010C390(p);
    func_0010A3F8(D_00393EB0);
    return p;
}
