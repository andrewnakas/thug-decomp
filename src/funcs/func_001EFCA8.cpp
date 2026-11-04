struct Ref_001EFCA8;

extern "C" void func_00183CB8(void* p, Ref_001EFCA8* ref);
extern "C" void func_00183C98(void* p, Ref_001EFCA8* ref);

struct Ref_001EFCA8 {
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

struct Frame_001EFCA8 {
    int m_name;
    void* m_data;
    void* m_pc;
    void* m_owner;
    void* m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
};

struct Obj_001EFCA8 {
    char m_pad0[0x10];
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1C;
    char m_pad20[0x38 - 0x20];
    int m_38;
    char m_pad3C[0x94 - 0x3C];
    Frame_001EFCA8* m_94;
    int m_98;
    int m_9C;
    int m_A0;
    int m_A4;
    int m_A8;
    char m_padAC[0xB0 - 0xAC];
    int m_B0;
    char m_padB4[0xBC - 0xB4];
    Ref_001EFCA8 m_BC;
    char m_padC0[0xC8 - 0xC0];
    int m_C8;
    int Return();
};

extern void* D_0038E8A4;
extern "C" void func_001F3108(void* mgr, int name);
extern "C" void func_001E6AE8(void* p, int flags);

int Obj_001EFCA8::Return()
{
    func_001F3108(D_0038E8A4, m_C8);
    int ret = m_B0;
    if (m_38) {
        m_38--;
        if (m_18) {
            func_001E6AE8(m_18, 3);
        }
        Frame_001EFCA8* f = &m_94[m_38];
        m_C8 = f->m_name;
        m_18 = f->m_data;
        m_10 = f->m_pc;
        m_BC.Set(f->m_owner);
        m_1C = f->m_10;
        m_A4 = f->m_14;
        if (m_A4) {
            m_98 = f->m_1C;
            m_A0 = f->m_24;
            m_9C = f->m_20;
            m_A8 = f->m_18;
        }
        m_B0 = f->m_28;
    } else {
        m_10 = 0;
    }
    return ret;
}
