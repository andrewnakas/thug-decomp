struct Ref_001EE640;

extern "C" void func_00183CB8(void* p, Ref_001EE640* ref);
extern "C" void func_00183C98(void* p, Ref_001EE640* ref);

struct Ref_001EE640 {
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

struct Obj_001EE640 {
    char m_pad0[0x10];
    void* m_10;
    void* m_14;
    void* m_18;
    char m_pad1[0xBC - 0x1C];
    Ref_001EE640 m_BC;
    char m_padC0[0xC8 - 0xC0];
    int m_C8;
    void Init(int name, void* script, void* params, void* owner);
};

extern void* D_0038E8A4;
extern "C" void* func_001EE948(Obj_001EE640* self, void* params);
extern "C" void func_001EE9E0(Obj_001EE640* self);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* mem);
extern "C" void* func_001F2F88(void* mgr, int name);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_001EEB60(Obj_001EE640* self);
extern "C" void* func_001ED6B8(void* s, void* script, int a);
extern "C" void func_001E6AC8(void* s, void* p);
extern "C" void* func_001F1248(Obj_001EE640* self);
extern "C" void func_001F1240(Obj_001EE640* self, int a);
extern "C" void func_001EEF18(Obj_001EE640* self, void* a, void* b);

void Obj_001EE640::Init(int name, void* script, void* params, void* owner)
{
    void* p = func_001EE948(this, params);
    func_001EE9E0(this);
    m_14 = func_001E6978(func_001190D0(8));
    m_C8 = name;
    m_BC.Set(owner);
    m_18 = func_001E6978(func_001190D0(8));
    if (script) {
        m_10 = script;
    } else {
        m_10 = func_001F2F88(D_0038E8A4, name);
        if (!m_10) {
            if (p) {
                func_001E6AE8(p, 3);
            }
            func_001EE9E0(this);
            func_001EEB60(this);
            return;
        }
    }
    m_10 = func_001ED6B8(m_18, m_10, 0);
    if (p) {
        func_001E6AC8(m_18, p);
        func_001E6AE8(p, 3);
    } else {
        func_001E6AC8(m_18, params);
    }
    if (func_001F1248(this)) {
        void* s = func_001E6978(func_001190D0(8));
        void* q = func_001F1248(this);
        func_001F1240(this, 0);
        func_001EEF18(this, q, s);
        if (s) {
            func_001E6AE8(s, 3);
        }
    }
}
