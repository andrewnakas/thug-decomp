struct Tag_001F5C08 {
    int m0;
    int m4;
    int m8;
    int mC;
};

struct Slot_001F5C08 {
    long m0;
    long m8;
    int m10;
    int m14;
};

struct Dma_001F5C08 {
    unsigned int m_buf;
    Tag_001F5C08* m_tags;
    int m_numTags;
    int mC;
    int m10;
    int m14;
    char m_pad18[0x44 - 0x18];
    int m44;
    char m_pad48[0x50 - 0x48];
    Slot_001F5C08* m_slots;
    int m_numSlots;
    int m58;
    int m5C;
    bool Init();
};

extern "C" void func_001F5B68(Tag_001F5C08* tag, unsigned int addr, int id, int qwc);
extern "C" void func_001F5AF8(int n);

bool Dma_001F5C08::Init()
{
    m44 = 1;
    mC = 0;
    m10 = 0;
    m14 = 0;
    m58 = 0;
    m5C = 0;
    int i;
    for (i = 0; i < m_numSlots; i++) {
        m_slots[i].m0 = -1;
        m_slots[i].m8 = -1;
        m_slots[i].m10 = 0;
        m_slots[i].m14 = 0;
    }
    for (i = 0; i < m_numTags; i++)
        func_001F5B68(&m_tags[i], (i * 0x800 + m_buf) & 0x0FFFFFFF, 3, 0x80);
    func_001F5B68(&m_tags[i], (unsigned int)m_tags & 0x0FFFFFFF, 2, 0);
    *(volatile unsigned int*)0x1000B420 = 0;
    *(volatile unsigned int*)0x1000B410 = m_buf & 0x0FFFFFFF;
    *(volatile unsigned int*)0x1000B430 = (unsigned int)m_tags & 0x0FFFFFFF;
    func_001F5AF8(5);
    return true;
}
