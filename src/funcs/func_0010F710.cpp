extern "C" void func_0010BEB8(void*);

struct Slot_0010F710 {
    int m0;
    int m_type;
    int m_id;
    int mC;
};

struct Cache_0010F710 {
    int m0[4];
    int m_count;
    int m14[2];
    Slot_0010F710 m_slots[0x7F];
    int m80C[3];
    void* m_data[0x7F];
    bool Free(int type, int id);
};

bool Cache_0010F710::Free(int type, int id)
{
    bool freed = false;
    for (int i = 0; i < m_count; i++) {
        if (m_slots[i].m_type == type && m_slots[i].m_id == id) {
            func_0010BEB8(m_data[i]);
            m_data[i] = 0;
            freed = true;
        }
    }
    return freed;
}
