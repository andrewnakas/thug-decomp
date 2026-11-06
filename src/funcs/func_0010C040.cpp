struct Block_0010C040 {
    char pad[0x38];
    int m_flags;
    char* m_end;
};

struct Heap_0010C040 {
    int m0;
    char* m_lo;
    int m_minFree;
    char* m_hi;
    Block_0010C040* m_last[2];
    void Attach(Block_0010C040* b);
};

void Heap_0010C040::Attach(Block_0010C040* b)
{
    m_last[(b->m_flags & 2) >> 1] = b;
    b->m_end = b->m_flags == 1 ? m_lo : m_hi;
}
