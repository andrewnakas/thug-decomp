struct Block_0010C258 {
    char pad[0x3C];
    char* m_end;
};

struct Heap_0010C258 {
    int m0;
    char* m_lo;
    int m_minFree;
    char* m_hi;
    Block_0010C258* m_last[2];
    int GetFree();
};

int Heap_0010C258::GetFree()
{
    char* lo;
    char* hi;
    if (m_last[0]) {
        lo = m_last[0]->m_end;
    } else {
        lo = m_lo;
    }
    if (m_last[1]) {
        hi = m_last[1]->m_end;
    } else {
        hi = m_hi;
    }
    return hi - lo;
}
