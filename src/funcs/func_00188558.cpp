extern "C" void func_001E6AE8(void* p, int mode);

struct E_00188558 {
    int m_key;
    unsigned int m_id;
    unsigned int m8;
    int m_used;
    int m10;
    int m14;
    void* m_obj;
};

struct L_00188558 {
    E_00188558* m_items;
    int m_count;
    void RemoveType(unsigned int type);
};

void L_00188558::RemoveType(unsigned int type)
{
    for (int i = 0; i < m_count; i++) {
        if (m_items[i].m8 == type || type == 0x8B713E0E) {
            m_items[i].m_id = 0xC377C572;
            if (m_items[i].m_obj) {
                func_001E6AE8(m_items[i].m_obj, 3);
                m_items[i].m_obj = 0;
            }
        }
    }
}
