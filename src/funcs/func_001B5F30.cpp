struct Obj_001B5F30;
struct Handle_001B5F30;

extern "C" void func_00183C98(Obj_001B5F30* o, Handle_001B5F30* h);
extern "C" void func_00183CB8(Obj_001B5F30* o, Handle_001B5F30* h);

struct Handle_001B5F30 {
    Obj_001B5F30* m_obj;
    Handle_001B5F30& operator=(Obj_001B5F30* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
};

struct Proxy_001B5F30 {
    char pad[0xBC];
    Handle_001B5F30 m_owner;
};

struct Comp_001B5F30 {
    char pad[0x30];
    float m30;
};

extern "C" void func_001F0E98(Obj_001B5F30* o, unsigned int name);
extern "C" Comp_001B5F30* func_00185578(Obj_001B5F30* o, unsigned int name);
extern "C" Proxy_001B5F30* func_001F0750(unsigned int name, int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void func_001B5E78(void* self);

struct C_001B5F30 {
    char pad[0xC];
    Obj_001B5F30* mC;
    char pad10[0x10];
    unsigned int m20;
    char pad24[0xA8];
    float mCC;
    void Init();
};

void C_001B5F30::Init()
{
    func_001F0E98(mC, 0xE630BF07);
    func_001F0E98(mC, 0x78131E4F);
    if (mCC > 0.0f)
        func_00185578(mC, 0x0A015E17)->m30 = mCC;
    Proxy_001B5F30* p;
    if (m20 & 4)
        p = func_001F0750(0xE630BF07, 0, 0, 0, -1, 0, 0, 0, 0, 0);
    else
        p = func_001F0750(0x78131E4F, 0, 0, 0, -1, 0, 0, 0, 0, 0);
    func_001B5E78(this);
    p->m_owner = mC;
}
