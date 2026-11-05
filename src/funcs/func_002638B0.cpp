extern "C" void func_00263938(void* self, int idx);

struct Entry_002638B0 {
    int m0;
    int m4;
    int m8;
    char pad[0x20 - 0xC];
};

struct Obj_002638B0 {
    Entry_002638B0 m_a[21];
    Entry_002638B0 m_b[21];
    char pad[0x544 - 0x540];
    int m544;
    int m548;
    char pad2[0x564 - 0x54C];
    int m564;
    int m568;
    char pad3[0x5C4 - 0x56C];
    int m5C4;
    void Select(int idx);
};

void Obj_002638B0::Select(int idx)
{
    if (idx == -1)
        idx = m5C4;
    else
        m5C4 = idx;
    func_00263938(this, m5C4);
    m544 = m_a[idx].m4;
    m548 = m_a[idx].m8;
    m564 = m_b[idx].m4;
    m568 = m_b[idx].m8;
}
