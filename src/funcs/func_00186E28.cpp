struct Entry_00186E28 {
    unsigned int m_key;
    int (*m_fn)();
};

struct Reg_00186E28 {
    char pad0[0x50];
    unsigned int m50;
    Entry_00186E28 m54[1];
    int Call(unsigned int key);
};

int Reg_00186E28::Call(unsigned int key)
{
    for (unsigned int i = 0; i < m50; i++) {
        if (m54[i].m_key == key)
            return m54[i].m_fn();
    }
    return 0;
}
