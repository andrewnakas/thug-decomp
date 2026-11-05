struct Entry_00108560 {
    int m0;
    void* m4;
    void* m8;
};

extern "C" void func_00109D88(void* table);
extern "C" Entry_00108560* func_00109D98(void* table, int a);

struct Obj_00108560 {
    int m0;
    int m4;
    int m8;
    void* m_table;
    Entry_00108560* m_cur;
    void* Find(Entry_00108560* key);
};

void* Obj_00108560::Find(Entry_00108560* key)
{
    func_00109D88(m_table);
    Entry_00108560* e;
    while ((e = func_00109D98(m_table, 0)) != 0) {
        if (e->m4 && e == key) {
            m_cur = e;
            if (e->m0) {
                return e->m8;
            }
            return e->m4;
        }
    }
    return 0;
}
