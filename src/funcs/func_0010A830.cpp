extern "C" void func_0010A3D0(int);
extern "C" void func_0010A3F8(int);
extern "C" void func_0010C390(void*);
extern int D_00393EB0;

class Heap_0010A830 {
public:
    char pad[0x80];
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void* AllocTemp(int size, int align);
};

struct Mem_0010A830 {
    char pad[0x8C];
    Heap_0010A830** m_stack;
    void* Alloc(int size, int align, Heap_0010A830* heap);
};

void* Mem_0010A830::Alloc(int size, int align, Heap_0010A830* heap)
{
    func_0010A3D0(D_00393EB0);
    if (!heap)
        heap = *m_stack;
    void* p = heap->AllocTemp(size, align);
    if (p)
        func_0010C390(p);
    func_0010A3F8(D_00393EB0);
    return p;
}
