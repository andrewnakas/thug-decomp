extern "C" void func_0018A928(void* table, int* key);
extern "C" void func_0018AA18(void* table, int* key, void* value);

struct S_001891C8 {
    char pad[0x18];
    int m_id;
};

struct R_001891C8 {
    char pad[0x44];
    int m_refs;
};
extern "C" R_001891C8* func_0018A8C0(void* table, int* key, int a);

struct L_001891C8 {
    void Add(int a, int b, unsigned int c, int d, int e, int type);
};

struct C_001891C8 {
    int m0;
    int m4;
    void* m_table;
    void* m_pending;
    char pad10[0x20 - 0x10];
    L_001891C8 m_log;
    void Register(S_001891C8* obj);
};

void C_001891C8::Register(S_001891C8* obj)
{
    int k0 = obj->m_id;
    R_001891C8* r = func_0018A8C0(m_pending, &k0, 1);
    if (r) {
        if (r->m_refs > 0) r->m_refs--;
        int k1 = obj->m_id;
        func_0018A928(m_pending, &k1);
    }
    int k2 = obj->m_id;
    func_0018AA18(m_table, &k2, obj);
    m_log.Add(0, obj->m_id, 0x36B2EE74, 0, 0, 4);
}
