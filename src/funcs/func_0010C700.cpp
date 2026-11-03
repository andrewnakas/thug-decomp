struct Stat_0010C700;
extern "C" void func_0010D0E8(Stat_0010C700* s, int n);
extern "C" void func_0010D110(Stat_0010C700* s, int n);

struct Stat_0010C700 {
    int m0;
    int m_cur;
    int m_max;
    Stat_0010C700 operator++(int)
    {
        Stat_0010C700 t = *this;
        func_0010D0E8(this, 1);
        return t;
    }
    Stat_0010C700 operator--(int)
    {
        Stat_0010C700 t = *this;
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

struct Block_0010C700 {
    Block_0010C700* m_next;
    int m_size;
};

struct Region_0010C700 {
    char pad[0x1C];
    Block_0010C700* m_free;
};

struct Heap_0010C700 {
    int m0;
    Stat_0010C700 m_used;
    Stat_0010C700 m_freeBlocks;
    Stat_0010C700 m_usedMem;
    Stat_0010C700 m_freeMem;
    int m34;
    int m_dir;
    char* m_top;
    Region_0010C700* m_region;
    void Free(Block_0010C700* b);
};

extern int D_00388B10;

void Heap_0010C700::Free(Block_0010C700* b)
{
    Block_0010C700* next = m_region->m_free;
    Block_0010C700* prev = 0;
    Block_0010C700* prevprev = 0;
    m_freeBlocks++;
    m_freeMem.Add(b->m_size);
    m_used--;
    m_usedMem.Sub(b->m_size);
    while (next && next < b) {
        prevprev = prev;
        prev = next;
        next = next->m_next;
    }
    b->m_next = next;
    if (next && (char*)b + D_00388B10 + b->m_size == (char*)next) {
        b->m_next = next->m_next;
        b->m_size += next->m_size + D_00388B10;
        m_freeBlocks--;
        int hdr = D_00388B10;
        m_freeMem.Add(hdr);
        m_usedMem.Sub(hdr);
    }
    if (prev) {
        if ((char*)prev + D_00388B10 + prev->m_size == (char*)b) {
            prev->m_size += b->m_size + D_00388B10;
            prev->m_next = b->m_next;
            m_freeBlocks--;
            int hdr = D_00388B10;
            m_freeMem.Add(hdr);
            b = prev;
            prev = prevprev;
            m_usedMem.Sub(hdr);
        } else {
            prev->m_next = b;
        }
    } else {
        m_region->m_free = b;
    }
    if (m_dir == 1 && !next && m_top == (char*)b + b->m_size + D_00388B10) {
        if (prev) {
            prev->m_next = 0;
        } else {
            m_region->m_free = 0;
        }
        int size = b->m_size;
        int hdr = D_00388B10;
        m_top -= (size + hdr) * m_dir;
        m_freeBlocks--;
        m_freeMem.Sub(b->m_size);
        m_usedMem.Sub(hdr);
    } else if (m_dir == -1 && !prev && m_top == (char*)b) {
        int size = b->m_size;
        int hdr = D_00388B10;
        m_top = (char*)b + (size + hdr);
        m_region->m_free = b->m_next;
        m_freeBlocks--;
        m_freeMem.Sub(b->m_size);
        m_usedMem.Sub(hdr);
    }
}
