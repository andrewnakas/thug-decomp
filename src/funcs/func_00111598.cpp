struct Ent_00111598 {
    int m_key;
    int m4;
    int m8;
    int mC;
};

struct Tbl_00111598 {
    char pad[0x40];
    Ent_00111598 m_ents[16];
    volatile int m_count;
    int Remove(int key);
};

int Tbl_00111598::Remove(int key)
{
    if (m_count <= 0) {
        return 0;
    }
    for (int i = 0; i < m_count; i++) {
        if (m_ents[i].m_key == key) {
            m_count--;
            m_ents[i] = m_ents[m_count];
            return 1;
        }
    }
    return 0;
}
