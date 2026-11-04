struct Entry_0010DE48 {
    int m0;
    int m4;
    unsigned short m_nameLen;
    unsigned short m_refs;
};

struct Pack_0010DE48 {
    int m0;
    int m4;
    int m_count;
    Entry_0010DE48 m_first;
};

extern "C" int func_00336228(const char*, const char*);
extern "C" Pack_0010DE48* func_0010D4E0(char*);
extern "C" Entry_0010DE48* func_0010D4A0(Entry_0010DE48*, int);
extern char* D_00396568[100];

bool func_0010DE48(const char* name)
{
    for (int i = 0; i < 100; i++) {
        if (D_00396568[i] && func_00336228(D_00396568[i], name) == 0) {
            Pack_0010DE48* pack = func_0010D4E0(D_00396568[i]);
            int n = pack->m_count;
            Entry_0010DE48* e = &pack->m_first;
            for (int j = 0; j < n; j++) {
                if (e->m_refs)
                    return true;
                e = func_0010D4A0(e, 1);
            }
        }
    }
    return false;
}
