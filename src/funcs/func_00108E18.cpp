struct Heap_00108E18 {
    char pad[0xD8];
    int m_D8;
};

extern Heap_00108E18* D_00388A70;
extern "C" void* func_00104760(int, int, int);
extern "C" void* func_001081A8(void*, void*, int);
extern "C" int func_0010A1E8(void*, const char*, void*);

struct Pending_00108E18 {
    int m_id;
    char m_name[0x40];
};

struct FileSys_00108E18 {
    char pad[0x14];
    void* m_list;
    int pad18;
    Pending_00108E18 m_pending[8];
    int m_numPending;
    void Mount(int id, void* data);
};

void FileSys_00108E18::Mount(int id, void* data)
{
    for (int i = 0; i < m_numPending; i++) {
        if (m_pending[i].m_id == id) {
            void* arc = func_001081A8(func_00104760(0x1C, D_00388A70->m_D8, 1), data, 0);
            func_0010A1E8(m_list, m_pending[i].m_name, arc);
            m_numPending--;
            m_pending[i] = m_pending[m_numPending];
            return;
        }
    }
}
