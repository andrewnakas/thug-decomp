extern "C" int func_0013C7B8(void* p, bool flag);
extern "C" int func_0013C718(void* p, int a);
extern "C" int func_0013D8B0(void* self, int a);
extern "C" int func_0013C3D8(void* item, void* obj, void* self, int p);
extern "C" void* func_00132150();
extern "C" void* func_001321E0(const char* name, int a, int b, bool flag);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" int func_001D0AA0(void* mgr);
extern "C" void* func_001D0708(void* mgr, const char* name, int a, int b, int c, int d, void* params, int e);
extern void* D_0038DB38;

struct Obj_0013D2F0 {
    int m0;
    int m4;
};

struct Params_0013D2F0 {
    int m0;
    int m4;
    int m8;
};

class C_0013D2F0 {
public:
    char m_pad0[0x10];
    void* m_items[18];
    int m_handles[18];
    int m_ids[18];
    int m_mask;
    char m_padEC[0x14];
    int m_value;
    void* m_objs[18];
    unsigned int m_names[18];
    unsigned int m_state;
    char m_pad198[0x18];
    unsigned long m_b0 : 1;
    unsigned long m_b1 : 3;
    unsigned long m_b4 : 1;
    unsigned long m_b5 : 1;
    unsigned long m_b6 : 10;
    short m_count;
    short m_numObjs;
    short m_numNames;
    int Add(const char* name, int id, bool shared, int a, int b, int c);
};

int C_0013D2F0::Add(const char* name, int id, bool shared, int a, int b, int c)
{
    Obj_0013D2F0* obj;
    m_b0 = 0;
    void* mgr = D_0038DB38;
    if (shared) {
        Params_0013D2F0 p;
        p.m0 = b;
        p.m4 = (bool)m_b5;
        p.m8 = a;
        obj = (Obj_0013D2F0*)func_001D0708(mgr, name, 0, 0, func_001D0AA0(mgr), 0, &p, 0);
        m_names[m_numNames] = func_001F0D78(name);
        m_numNames++;
    } else {
        func_0010BFC0(name);
        obj = (Obj_0013D2F0*)func_001321E0(name, a, b, m_b5);
        func_0010BFC8();
        m_objs[m_numObjs] = obj;
        m_numObjs++;
    }
    m_items[m_count] = func_00132150();
    if (m_items[m_count]) {
        func_0013C3D8(m_items[m_count], obj, this, c);
        m_handles[m_count] = obj->m4;
        func_0013C7B8(m_items[m_count], m_b4);
        m_ids[m_count] = id;
        m_mask |= 1 << m_count;
        if (m_value) {
            func_0013C718(m_items[m_count], m_value);
        }
        m_count++;
        func_0013D8B0(this, 0);
    }
    if (m_count == 1) {
        m_state = func_001F0D78(name);
    }
    return 0;
}
