struct S_0013D648A {
    char m_pad0[0xB0];
    int m_flags;
};

struct S_0013D648B {
    char m_pad0[0xB0];
    int m_flags;
};

extern void* D_0038DB38;
extern "C" S_0013D648B* func_001D0638(void* table, int key, int create);

class C_0013D648 {
public:
    char m_pad0[0x104];
    S_0013D648A* m_items[18];
    int m_keys[25];
    char m_pad1B0[4];
    short m_count;
    short m_keyCount;
    int GetFlags();
};

int C_0013D648::GetFlags()
{
    int flags = 0;
    for (short i = 0; i < m_count; i++) {
        flags |= m_items[i]->m_flags;
    }
    for (short j = 0; j < m_keyCount; j++) {
        S_0013D648B* p = func_001D0638(D_0038DB38, m_keys[j], 1);
        if (p) {
            flags |= p->m_flags;
        }
    }
    return flags;
}
