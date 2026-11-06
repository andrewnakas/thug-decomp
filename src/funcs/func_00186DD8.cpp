struct Entry_00186DD8 {
    unsigned int m_key;
    int (*m_fn)();
};

struct Reg_00186DD8 {
    char pad0[0x50];
    unsigned int m50;
    Entry_00186DD8 m54[1];
    void Add(unsigned int key, int (*fn)(), void (*init)());
};

void Reg_00186DD8::Add(unsigned int key, int (*fn)(), void (*init)())
{
    m54[m50].m_key = key;
    m54[m50].m_fn = fn;
    m50++;
    if (init)
        init();
}
