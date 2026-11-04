extern void* D_00388A70;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E69A0(void* mem, void* src);

struct E_00187F90 {
    int m_key;
    unsigned int m_id;
    int m8;
    int m_used;
    int m10;
    int m14;
    void* m_obj;
};

struct L_00187F90 {
    E_00187F90* m_items;
    int m_count;
    int m8;
    int m_dirty;
    void Add(int key, unsigned int id, int c, int d, void* src);
};

void L_00187F90::Add(int key, unsigned int id, int c, int d, void* src)
{
    E_00187F90* e;
    if (!m_items) {
        m_count = 1;
        m_items = (E_00187F90*)func_0010A638(D_00388A70, sizeof(E_00187F90), 1, 0);
        e = m_items;
    } else {
        int i;
        for (i = 0; i < m_count; i++) {
            if (m_items[i].m_key == key) {
                e = &m_items[i];
                if (e->m_obj) func_001E6AE8(e->m_obj, 3);
                goto fill;
            }
        }
        for (i = 0; i < m_count; i++) {
            if (m_items[i].m_id == 0xC377C572) {
                e = &m_items[i];
                goto fill;
            }
        }
        E_00187F90* old = m_items;
        m_items = (E_00187F90*)func_0010A638(D_00388A70, (m_count + 1) * sizeof(E_00187F90), 1, 0);
        for (i = 0; i < m_count; i++) m_items[i] = old[i];
        if (old) func_0010A8D8(D_00388A70, old);
        e = &m_items[m_count];
        m_count++;
    }
fill:
    e->m10 = d;
    e->m_used = 1;
    e->m8 = c;
    if (src) e->m_obj = func_001E69A0(func_001190D0(8), src);
    else e->m_obj = 0;
    e->m_id = id;
    e->m_key = key;
    m_dirty = 1;
}
