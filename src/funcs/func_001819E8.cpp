struct Entry_001819E8 {
    int m_id;
    char pad4[0x34];
    unsigned int m38;
    char pad3C[0xC];
};

struct List_001819E8 {
    char pad0[0x18];
    int m_count;
    char pad1C[8];
    Entry_001819E8* m_entries;
    char pad28[0x18];
    List_001819E8* m_next;
};

extern List_001819E8* D_00394310;

extern "C" Entry_001819E8* func_001819E8(int id)
{
    for (List_001819E8* l = D_00394310; l; l = l->m_next) {
        Entry_001819E8* e = l->m_entries;
        for (int i = 0; i < l->m_count; i++, e++) {
            if (e->m_id == id && (e->m38 & 1)) {
                return e;
            }
        }
    }
    return 0;
}
