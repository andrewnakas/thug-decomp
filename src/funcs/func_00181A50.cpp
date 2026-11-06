struct Entry_00181A50 {
    int m_id;
    int m_type;
    char pad8[0x40];
};

struct List_00181A50 {
    char pad0[0x18];
    int m_count;
    char pad1C[8];
    Entry_00181A50* m_entries;
    char pad28[0x18];
    List_00181A50* m_next;
};

extern List_00181A50* D_00394310;

extern "C" Entry_00181A50* func_00181A50(int id, int type)
{
    for (List_00181A50* l = D_00394310; l; l = l->m_next) {
        Entry_00181A50* e = l->m_entries;
        for (int i = 0; i < l->m_count; i++, e++) {
            if (e->m_id == id && e->m_type == type) {
                return e;
            }
        }
    }
    return 0;
}
