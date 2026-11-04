struct Entry_001BB1E0 {
    char pad[0x70];
    int m_id;
    char m_active;
    char pad75[0xB];
};

struct List_001BB1E0 {
    char pad[0x30];
    Entry_001BB1E0 m_entries[32];
    int m_count;
};

extern "C" void func_001BB2E8(void* self, void* arg, int id, int a, int b);

extern "C" void func_001BB1E0(void* self, void* arg, List_001BB1E0* list)
{
    int i = list->m_count;
    while (i-- != 0) {
        Entry_001BB1E0* e = &list->m_entries[i];
        if (!e->m_active)
            continue;
        int j;
        for (j = i + 1; j < list->m_count; j++) {
            Entry_001BB1E0* f = &list->m_entries[j];
            if (e->m_active && e->m_id == f->m_id)
                break;
        }
        if (j == list->m_count)
            func_001BB2E8(self, arg, e->m_id, 0, 0);
    }
}
