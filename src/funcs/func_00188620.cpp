extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_0010A950(void* p, int v);

struct Heap_00188620 {
    char pad0[0xE4];
    int mE4;
};

extern Heap_00188620* D_00388A70;

struct E_00188620 {
    int m_key;
    unsigned int m_id;
    unsigned int m8;
    int m_used;
    int m10;
    int m14;
    void* m_obj;
};

struct L_00188620 {
    E_00188620* m_items;
    int m_count;
    int m_alive;
    /* Equivalence fix, proven by the game's instructions: a 32-bit store, `addiu $v0, $zero, 0x1` (0x00188690) /
       `sw $v0, 0xC($s0)` (0x0018869C), so m_changed is int, not bool (the old unit's sb left 0xD-0xF untouched). */
    int m_changed;
    void Compact();
};

void L_00188620::Compact()
{
    int i;
    int dead = 0;
    if (!m_items) {
        return;
    }
    for (i = 0; i < m_count; i++) {
        if (m_items[i].m_id == 0xC377C572) {
            dead++;
        }
    }
    int n = m_count;
    if (!dead) {
        return;
    }
    m_changed = 1;
    int live = n - dead;
    if (live == 0) {
        for (int j = 0; j < m_count; j++) {
            if (m_items[j].m_obj) {
                func_001E6AE8(m_items[j].m_obj, 3);
                m_items[j].m_obj = 0;
            }
        }
        if (m_items) {
            func_0010A8D8(D_00388A70, m_items);
        }
        m_items = 0;
        m_count = 0;
        return;
    }
    func_0010A950(D_00388A70, D_00388A70->mE4);
    E_00188620* items = (E_00188620*)func_0010A638(D_00388A70, live * 0x1C, 1, 0);
    func_0010A9B0(D_00388A70);
    int k = 0;
    for (i = 0; i < m_count; i++) {
        if (m_items[i].m_id != 0xC377C572) {
            items[k++] = m_items[i];
        } else if (m_items[i].m_obj) {
            func_001E6AE8(m_items[i].m_obj, 3);
            m_items[i].m_obj = 0;
        }
    }
    if (m_items) {
        func_0010A8D8(D_00388A70, m_items);
    }
    m_items = items;
    m_count = live;
}
