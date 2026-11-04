struct Block_0010CFD8 {
    void* m_heap;
    unsigned int m_size;
};

extern "C" Block_0010CFD8* func_0010C3A0(void*);
extern "C" void func_0010BFE0(Block_0010CFD8*);
extern "C" void func_0010BFD8(Block_0010CFD8*);
extern "C" void func_0010D0E8(void*, int);
extern unsigned int D_00388B10;

class Heap_0010CFD8 {
public:
    int m0;
    char m_stats[0x80 - 4];
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual int Free(void* p);
    void* Shrink(unsigned int size, char* ptr);
};

void* Heap_0010CFD8::Shrink(unsigned int size, char* ptr)
{
    Block_0010CFD8* blk = func_0010C3A0(ptr);
    unsigned int extra = blk->m_size - size;
    extra &= 0xFFFFFFF0;
    if (D_00388B10 < extra) {
        Block_0010CFD8* nb = (Block_0010CFD8*)(ptr + blk->m_size - extra);
        nb->m_heap = this;
        nb->m_size = extra - D_00388B10;
        func_0010BFD8(nb);
        func_0010D0E8(m_stats, 1);
        Free(nb);
        func_0010BFE0(blk);
        blk->m_size -= extra;
        func_0010BFD8(blk);
    }
    return ptr;
}
