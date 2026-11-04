struct Obj_00130150;
struct Handle_00130150;

extern "C" void func_00183C98(Obj_00130150* o, Handle_00130150* h);
extern "C" void func_00183CB8(Obj_00130150* o, Handle_00130150* h);

struct ObjBase_00130150 {
    int m0;
    int m4;
    virtual ~ObjBase_00130150();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8(void* s);
};

struct Obj_00130150 : ObjBase_00130150 {
};

struct Handle_00130150 {
    Obj_00130150* m_obj;
    Handle_00130150* m_prev;
    Handle_00130150* m_next;
    Handle_00130150(Obj_00130150* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_00130150(const Handle_00130150& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_00130150()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00130150& operator=(Obj_00130150* o)
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
    Handle_00130150& operator=(const Handle_00130150& h) { return *this = h.m_obj; }
    Obj_00130150* operator->() const { return m_obj; }
    operator Obj_00130150*() const { return m_obj; }
};

static inline Handle_00130150 Make_00130150(const Handle_00130150& t)
{
    return t;
}

extern void* D_00389A30;
extern "C" int func_0012E438(void* mgr, void* params, unsigned int name);
extern "C" Handle_00130150 func_0012DB48(void* mgr, int id, int flag);
extern "C" int func_001E8708(void* params, unsigned int name);

struct Script_00130150 {
    char pad[0x18];
    void* m18;
};

bool Cmd_00130150(void* params, Script_00130150* script)
{
    void* mgr = D_00389A30;
    Handle_00130150 h = Make_00130150((Obj_00130150*)0);
    int id = func_0012E438(mgr, params, 0x40C698AF);
    if (id)
        h = func_0012DB48(mgr, id, 0);
    if (h) {
        h->V8(script->m18);
        return true;
    }
    func_001E8708(params, 0x3D92465E);
    return false;
}
