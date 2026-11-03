struct Block_0010CE18 {
    int m0;
    unsigned int m_size;
};

extern "C" Block_0010CE18* func_0010C3A0(void*);
extern "C" void func_0010BFE0(Block_0010CE18*);
extern "C" void func_0010BFD8(Block_0010CE18*);
extern "C" void func_0010D110(void*, int);
extern int D_00388B10;

class Heap_0010CE18 {
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
    void* Grow(unsigned int size, void* ptr);
};

void* Heap_0010CE18::Grow(unsigned int size, void* ptr)
{
    Block_0010CE18* blk = func_0010C3A0(ptr);
    size = (size + 15) & 0xFFFFFFF0;
    Block_0010CE18* nb = func_0010C3A0(Alloc(size - blk->m_size, 1));
    func_0010BFE0(blk);
    func_0010BFE0(nb);
    func_0010D110(m_stats, 1);
    int g = D_00388B10;
    nb->m_size = size + g;
    func_0010BFD8(nb);
    return (char*)nb + g;
}
