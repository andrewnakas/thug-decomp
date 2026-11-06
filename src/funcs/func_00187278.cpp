struct Entry_00187278 {
    unsigned int m_key;
    void* m_fn;
};

extern void* D_004655E8[];

struct Reg_00187278 {
    char pad0[0x50];
    unsigned int m50;
    Entry_00187278 m54[1];
    void* Find(unsigned int key);
};

void* Reg_00187278::Find(unsigned int key)
{
    for (unsigned int i = 0; i < m50; i++) {
        if (m54[i].m_key == key)
            return D_004655E8[i];
    }
    return 0;
}
