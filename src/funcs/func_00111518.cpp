struct Entry_00111518 {
    int m_key;
    int m_val;
    int m8[2];
};

struct Table_00111518 {
    char pad[0x40];
    Entry_00111518 m_e[16];
    int m_count;
    int Find(int key);
};

int Table_00111518::Find(int key)
{
    for (int i = 0; i < m_count; i++) {
        if (m_e[i].m_key == key)
            return m_e[i].m_val;
    }
    return 0;
}
