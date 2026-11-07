struct Ent_001E6178 {
    int m_key;
    void* m_val;
};

extern int D_00388818;
extern Ent_001E6178* D_0038E580;

extern "C" void* func_001E6178(int key)
{
    if (!D_00388818)
        return 0;
    Ent_001E6178* e = &D_0038E580[(key & 0xFFFF) * 10];
    int i = 10;
    while (e->m_val) {
        if (e->m_key == key) return e->m_val;
        if (--i == 0) break;
        e++;
    }
    return 0;
}
