struct Heap_0010C330;

struct Block_0010C330 {
    Heap_0010C330* m_heap;
    int m4;
    unsigned int m_magic;
};

extern "C" Block_0010C330* func_0010C3A0(void* p);

struct Heap_0010C330 {
    char pad0[0x80];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void FreeBlock(Block_0010C330* b);
};

extern "C" Heap_0010C330* func_0010C330(void* p)
{
    Block_0010C330* b = func_0010C3A0(p);
    Heap_0010C330* h = b->m_heap;
    h->FreeBlock(b);
    b->m_magic = 0xDEADDEAD;
    return h;
}
