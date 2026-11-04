struct Ref_001EE9E0;

extern "C" void func_00183CB8(void* p, Ref_001EE9E0* ref);
extern "C" void func_00183C98(void* p, Ref_001EE9E0* ref);

struct Ref_001EE9E0 {
    void* m_ptr;
    void Set(void* p)
    {
        if (m_ptr) {
            func_00183CB8(m_ptr, this);
            m_ptr = 0;
        }
        m_ptr = p;
        if (p) {
            func_00183C98(p, this);
        }
    }
};

struct Entry_001EE9E0 {
    int m_name;
    void* m_data;
    char m_pad[0x2C - 0x8];
};

struct Obj_001EE9E0 {
    char m_pad0[0xC];
    void* m_C;
    void* m_10;
    void* m_14;
    void* m_18;
    int m_1C;
    char m_20[0x14];
    char* m_34;
    int m_38;
    Entry_001EE9E0 m_3C[2];
    Entry_001EE9E0* m_94;
    int m_98;
    char m_pad9C[0xA4 - 0x9C];
    int m_A4;
    int m_A8;
    char m_padAC[0xB0 - 0xAC];
    int m_B0;
    int m_B4;
    char m_padB8[0xBC - 0xB8];
    Ref_001EE9E0 m_BC;
    char m_padC0[0xC8 - 0xC0];
    int m_C8;
    void Clear();
};

extern void* D_0038E8A4;
extern "C" void func_0010BEB8(void* p);
extern "C" void func_001F3108(void* mgr, int name);
extern "C" void func_001E6AE8(void* p, int flags);

void Obj_001EE9E0::Clear()
{
    if (m_C) {
        func_0010BEB8(m_C);
        m_C = 0;
    }
    void* mgr = D_0038E8A4;
    if (m_10) {
        func_001F3108(mgr, m_C8);
    }
    m_10 = 0;
    if (m_18) {
        func_001E6AE8(m_18, 3);
        m_18 = 0;
    }
    if (m_14) {
        func_001E6AE8(m_14, 3);
        m_14 = 0;
    }
    for (int i = 0; i < m_38; i++) {
        func_001F3108(mgr, m_94[i].m_name);
        if (m_94[i].m_data) {
            func_001E6AE8(m_94[i].m_data, 3);
            m_94[i].m_data = 0;
        }
    }
    m_38 = 0;
    if (m_94 != m_3C) {
        func_0010BEB8(m_94);
    }
    m_94 = m_3C;
    m_1C = 0;
    if (m_34 != m_20) {
        func_0010BEB8(m_34);
    }
    m_34 = m_20;
    m_98 = 0;
    m_A4 = 0;
    m_A8 = 0;
    m_BC.Set(0);
    m_C8 = 0;
    m_B0 = 0;
    m_B4 = 0;
}
