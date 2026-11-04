struct Heap_001EF9C0 {
    char m_pad[0xEC];
    int m_EC;
};

struct Entry_001EF9C0 {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
};

struct Frame_001EF9C0 {
    char m_pad0[0x10];
    Entry_001EF9C0* m_10;
    char m_pad14[0x2C - 0x14];
};

struct Obj_001EF9C0 {
    char m_pad0[0x10];
    int m_10;
    char m_pad14[0x1C - 0x14];
    Entry_001EF9C0* m_1C;
    Entry_001EF9C0 m_20[1];
    Entry_001EF9C0* m_34;
    int m_38;
    char m_pad3C[0x94 - 0x3C];
    Frame_001EF9C0* m_94;
    void Push();
};

extern Heap_001EF9C0* D_00388A70;
extern "C" void func_0010A950(void* heap, int a);
extern "C" void func_0010A9B0(void* heap);
extern "C" Entry_001EF9C0* func_0010BDE0(int size);

void Obj_001EF9C0::Push()
{
    m_10++;
    Entry_001EF9C0* old = m_1C;
    if (old == m_20) {
        func_0010A950(D_00388A70, D_00388A70->m_EC);
        m_34 = func_0010BDE0(0xC8);
        func_0010A9B0(D_00388A70);
        int i;
        for (i = 0; i < 1; i++) {
            m_34[i] = old[i];
        }
        m_1C = m_34;
        for (i = 0; i < m_38; i++) {
            if (m_94[i].m_10) {
                m_94[i].m_10 = (Entry_001EF9C0*)((char*)m_34 + ((char*)m_94[i].m_10 - 0x20 - (char*)this));
            }
        }
    }
    if (m_1C) {
        m_1C++;
    } else {
        m_1C = m_34;
    }
    m_1C->m_0 = m_10;
    m_1C->m_4 = 0;
    m_1C->m_8 = 0;
    m_1C->m_C = 1;
    m_1C->m_10 = 0;
}
