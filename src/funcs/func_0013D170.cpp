extern "C" int func_0013C7B8(void* p, bool flag);
extern "C" int func_0013C718(void* p, int a);
extern "C" int func_0013D8B0(void* self, int a);
extern "C" int func_0013C3D8(void* item, void* obj, void* self, int p);
extern "C" void* func_00132150();
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void* func_001D0638(void* mgr, unsigned int name, int create);
extern char D_0035E990[];
extern void* D_0038DB38;

struct Obj_0013D170 {
    int m0;
    int m4;
};

class C_0013D170 {
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
    int AddByName(unsigned int name, int id, int c);
};

int C_0013D170::AddByName(unsigned int name, int id, int c)
{
    m_b0 = 0;
    Obj_0013D170* obj = (Obj_0013D170*)func_001D0638(D_0038DB38, name, 0);
    m_names[m_numNames] = name;
    m_numNames++;
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
        m_state = func_001F0D78(D_0035E990);
    }
    return 0;
}
