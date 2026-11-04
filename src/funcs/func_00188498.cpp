extern "C" void func_001E6AE8(void* p, int mode);

struct E_00188498 {
    int m_key;
    unsigned int m_id;
    unsigned int m8;
    int m_used;
    int m10;
    int m14;
    void* m_obj;
};

struct L_00188498 {
    E_00188498* m_items;
    int m_count;
    void Remove(int key);
};

void L_00188498::Remove(int key)
{
    for (int i = 0; i < m_count; i++) {
        if (m_items[i].m_key == key) {
            m_items[i].m_key = 0;
            m_items[i].m_id = 0xC377C572;
            if (m_items[i].m_obj) {
                func_001E6AE8(m_items[i].m_obj, 3);
                m_items[i].m_obj = 0;
            }
        }
    }
}
