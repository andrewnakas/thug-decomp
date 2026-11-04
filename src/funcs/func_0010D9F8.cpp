struct Entry_0010D9F8 {
    int m0;
    int m4;
    int m8;
    int m_id;
};

struct Pack_0010D9F8 {
    int m0;
    int m4;
    int m_count;
    Entry_0010D9F8 m_first;
};

extern "C" Pack_0010D9F8* func_0010D4E0(char*);
extern "C" Entry_0010D9F8* func_0010D4A0(Entry_0010D9F8*, int);
extern char* D_00396568[100];

Entry_0010D9F8* func_0010D9F8(int id)
{
    for (int i = 0; i < 100; i++) {
        if (D_00396568[i]) {
            Pack_0010D9F8* pack = func_0010D4E0(D_00396568[i]);
            int n = pack->m_count;
            Entry_0010D9F8* e = &pack->m_first;
            for (int j = 0; j < n; j++) {
                if (e->m_id == id)
                    return e;
                e = func_0010D4A0(e, 1);
            }
        }
    }
    return 0;
}
