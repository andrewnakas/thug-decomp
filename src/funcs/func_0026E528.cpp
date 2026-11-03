struct Entry_0026E528 {
    char data[0x14];
};

struct Table_0026E528 {
    int m0;
    int m_count;
    Entry_0026E528* m_entries;
    int Insert(int score, int extra);
};

extern "C" void func_0026E060(Entry_0026E528* e, int is_new);
extern "C" int func_0026E148(Entry_0026E528* e);
extern "C" void func_0026E0C0(Entry_0026E528* dst, Entry_0026E528* src);
extern "C" void func_0026E050(Entry_0026E528* e, int score);
extern "C" void func_0026E058(Entry_0026E528* e, int extra);
extern "C" void func_0026E030(Entry_0026E528* e, char* name);

extern char D_00391450[];

int Table_0026E528::Insert(int score, int extra)
{
    int i;
    for (i = 0; i < m_count; i++) {
        func_0026E060(&m_entries[i], 0);
    }
    for (i = 0; i < m_count; i++) {
        if (func_0026E148(&m_entries[i]) < score) {
            for (int j = m_count - 1; i < j; j--) {
                func_0026E0C0(&m_entries[j], &m_entries[j - 1]);
            }
            func_0026E050(&m_entries[i], score);
            func_0026E058(&m_entries[i], extra);
            func_0026E030(&m_entries[i], D_00391450);
            func_0026E060(&m_entries[i], 1);
            return i;
        }
    }
    return -1;
}
