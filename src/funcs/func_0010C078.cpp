struct Block_0010C078 {
    char pad[0x38];
    int m_flags;
    char* m_end;
};

struct Heap_0010C078 {
    int m0;
    char* m_lo;
    int m_minFree;
    char* m_hi;
    Block_0010C078* m_last[2];
    void Release(Block_0010C078* b);
};

void Heap_0010C078::Release(Block_0010C078* b)
{
    m_last[(b->m_flags & 2) >> 1] = 0;
}
