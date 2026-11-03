struct Stat_0010CB20;
extern "C" int func_0010D0E8(Stat_0010CB20* s, int n);
extern "C" int func_0010D110(Stat_0010CB20* s, int n);

struct Stat_0010CB20 {
    int m0;
    int m_cur;
    int m_max;
    Stat_0010CB20 operator++(int)
    {
        Stat_0010CB20 t = *this;
        func_0010D0E8(this, 1);
        return t;
    }
    Stat_0010CB20 operator--(int)
    {
        Stat_0010CB20 t = *this;
        func_0010D110(this, 1);
        return t;
    }
    void Add(int n)
    {
        m_cur += n;
        if (m_cur > m_max) {
            m_max = m_cur;
        }
    }
    void Sub(int n) { m_cur -= n; }
};

struct Block_0010CB20 {
    Block_0010CB20* m_next;
    unsigned int m_size;
};

struct Region_0010CB20 {
    char pad[0x1C];
    Block_0010CB20* m_free;
};

struct Heap_0010CB20 {
    int m0;
    Stat_0010CB20 m_used;
    Stat_0010CB20 m_freeBlocks;
    Stat_0010CB20 m_usedMem;
    Stat_0010CB20 m_freeMem;
    int m_34;
    int m_dir;
    char* m_top;
    Region_0010CB20* m_region;
    char pad44[0x80 - 0x44];

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void FreeBlock(Block_0010CB20* b);

    void* Alloc(int n, int flags);
};

extern int D_00388B10;
extern char D_0035B5E0[];
extern char D_0035B608[];
extern "C" Block_0010CB20* func_0010C098(int region, Heap_0010CB20* heap, int size, int flags);
extern "C" void func_0010BFD8(Block_0010CB20* b);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_00219508(int, int);

void* Heap_0010CB20::Alloc(int n, int flags)
{
    unsigned int size = (n + 15) & 0xFFFFFFF0;
    Block_0010CB20* best = 0;
    Block_0010CB20* prev = 0;
    Block_0010CB20* bestPrev = 0;
    for (Block_0010CB20* b = m_region->m_free; b; b = b->m_next) {
        if (b->m_size >= size && (!best || b->m_size < best->m_size)) {
            bestPrev = prev;
            best = b;
        }
        prev = b;
    }
    if (best) {
        if (bestPrev) {
            bestPrev->m_next = best->m_next;
        } else {
            m_region->m_free = best->m_next;
        }
        best->m_next = (Block_0010CB20*)this;
        m_freeBlocks--;
        m_used++;
        m_freeMem.Sub(best->m_size);
        m_usedMem.Add(best->m_size);
        int rem = best->m_size - size - D_00388B10;
        Block_0010CB20* nb = (Block_0010CB20*)((char*)best + D_00388B10 + size);
        if (rem > 0) {
            best->m_size = size;
            nb->m_size = rem;
            nb->m_next = (Block_0010CB20*)this;
            m_used++;
            FreeBlock(nb);
        }
    } else {
        int total = size + D_00388B10;
        best = func_0010C098(m_34, this, total, flags);
        if (best) {
            best->m_size = size;
            best->m_next = (Block_0010CB20*)this;
            m_used++;
            m_usedMem.Add(total);
        }
    }
    if (best) {
        func_0010BFD8(best);
        return (char*)best + D_00388B10;
    }
    func_00103F28(D_0035B5E0);
    func_00103F28(D_0035B608, size);
    func_00219508(0, 0);
    return 0;
}
