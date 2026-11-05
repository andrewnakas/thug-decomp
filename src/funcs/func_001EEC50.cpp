struct Ref_001EEC50;
extern "C" void func_00183CB8(void* obj, Ref_001EEC50* ref);

struct Ref_001EEC50 {
    void* m_p;
    void Clear()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = 0;
    }
};

struct Entry_001EEC50 {
    char m_pad[0xC];
    void* m_obj;
    char m_pad10[0x1C];
};

struct Obj_001EEC50;
extern "C" void func_001EE5E8(Obj_001EEC50* self);

struct Obj_001EEC50 {
    char m_pad0[0x38];
    int m_count;
    char m_pad3C[0x58];
    Entry_001EEC50* m_entries;
    char m_pad98[0x24];
    Ref_001EEC50 m_ref;
    void Forget(void* obj);
};

void Obj_001EEC50::Forget(void* obj)
{
    if (!obj)
        return;
    Ref_001EEC50* r = &m_ref;
    if (r->m_p == obj)
        r->Clear();
    for (int i = 0; i < m_count; i++) {
        if (m_entries[i].m_obj == obj)
            m_entries[i].m_obj = 0;
    }
    func_001EE5E8(this);
}
