struct Block_0010CED0 {
    int m0;
    unsigned int m_size;
};

extern "C" Block_0010CED0* func_0010C3A0(void*);
extern "C" void func_0010BFE0(Block_0010CED0*);
extern "C" void func_0010BFD8(Block_0010CED0*);
extern "C" void func_0010D110(void*, int);
extern int D_00388B10;

class Heap_0010CED0 {
public:
    int m0;
    char m_stats[0x80 - 4];
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void* Alloc(int size, int align);
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void Free(void* p);
    void* Expand(unsigned int size, char* ptr);
};

void* Heap_0010CED0::Expand(unsigned int size, char* ptr)
{
    Block_0010CED0* blk = func_0010C3A0(ptr);
    size = (size + 15) & 0xFFFFFFF0;
    if (!(blk->m_size < size))
        return ptr;
    Block_0010CED0* nb = func_0010C3A0(Alloc(size - blk->m_size, 1));
    if (ptr + blk->m_size != (char*)nb) {
        Free(nb);
        return 0;
    }
    func_0010BFE0(blk);
    func_0010BFE0(nb);
    unsigned int n = nb->m_size;
    func_0010D110(m_stats, 1);
    blk->m_size += n + D_00388B10;
    func_0010BFD8(blk);
    return ptr;
}
