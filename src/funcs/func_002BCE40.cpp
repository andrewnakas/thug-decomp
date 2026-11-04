struct Data_002BCE40 {
    int d[0x3A98 / 4];
};

struct Obj_002BCE40 {
    char pad[0x6A60];
    Data_002BCE40* m_data;
    unsigned int m_flags;
    void Set(const Data_002BCE40* src, bool full);
};

void Obj_002BCE40::Set(const Data_002BCE40* src, bool full)
{
    *m_data = *src;
    unsigned int f = m_flags;
    m_flags = f | 6;
    if (full) m_flags = f | 0xE;
}
