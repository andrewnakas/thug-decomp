struct Region_0010ACE0 {
    int m0;
    void* m_heap;
};

struct Mgr_0010ACE0 {
    void* m_words[0x100];
    void* GetHeap(unsigned int crc);
};

extern "C" Region_0010ACE0* func_0010BC50(Mgr_0010ACE0* self, unsigned int crc);

void* Mgr_0010ACE0::GetHeap(unsigned int crc)
{
    void* heap = 0;
    Region_0010ACE0* r = func_0010BC50(this, crc);
    if (r) {
        return r->m_heap;
    }
    switch (crc) {
    case 0x0C7800B0: heap = m_words[0xDC / 4]; break;
    case 0x8FDB68AF: heap = m_words[0xD8 / 4]; break;
    case 0x62F3A0F3: heap = m_words[0xE4 / 4]; break;
    case 0xE3551D2E: heap = m_words[0xF4 / 4]; break;
    case 0x96D29D93: heap = m_words[0xFC / 4]; break;
    case 0xFCD5166B: heap = m_words[0x104 / 4]; break;
    case 0x90020867: heap = m_words[0x108 / 4]; break;
    case 0x0FA33D9B: heap = m_words[0xEC / 4]; break;
    case 0x70CB0238: heap = m_words[0x11C / 4]; break;
    case 0xC3909393: heap = m_words[0x148 / 4]; break;
    case 0xB497A305: heap = m_words[0x14C / 4]; break;
    case 0x2D9EF2BF: heap = m_words[0x150 / 4]; break;
    case 0x5A99C229: heap = m_words[0x154 / 4]; break;
    case 0x572A9F4C: heap = m_words[0x188 / 4]; break;
    case 0x202DAFDA: heap = m_words[0x18C / 4]; break;
    case 0xB924FE60: heap = m_words[0x190 / 4]; break;
    case 0xCE23CEF6: heap = m_words[0x194 / 4]; break;
    case 0x08682D24: heap = m_words[0x3EC / 4]; break;
    case 0x17ECB880: heap = m_words[0x3F4 / 4]; break;
    case 0x7ED56B49: heap = m_words[0x114 / 4]; break;
    case 0x25D71469: heap = m_words[0x110 / 4]; break;
    }
    return heap;
}
