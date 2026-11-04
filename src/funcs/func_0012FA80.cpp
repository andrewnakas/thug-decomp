struct Obj_0012FA80;
struct Handle_0012FA80;

extern "C" void func_00183C98(Obj_0012FA80* o, Handle_0012FA80* h);
extern "C" void func_00183CB8(Obj_0012FA80* o, Handle_0012FA80* h);

struct Obj_0012FA80 {
    char pad[0x1C];
    unsigned int m1C;
};

struct Handle_0012FA80 {
    Obj_0012FA80* m_obj;
    Handle_0012FA80* m_prev;
    Handle_0012FA80* m_next;
    Handle_0012FA80(const Handle_0012FA80& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012FA80()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012FA80& operator=(Obj_0012FA80* o)
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
    Obj_0012FA80* operator->() const { return m_obj; }
    operator Obj_0012FA80*() const { return m_obj; }
};

static inline Handle_0012FA80 Make_0012FA80(const Handle_0012FA80& t)
{
    return t;
}

extern void* D_00389A30;
extern "C" Handle_0012FA80 func_0012DC18(void* mgr, void* params, unsigned int name, int flag);
extern "C" int func_001E7C80(void* params, unsigned int name, void** out, int req);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" bool func_00128530(Obj_0012FA80* o, void* s, bool a, bool b);
extern "C" bool func_00126490(Obj_0012FA80* o, void* s);

bool Cmd_0012FA80(void* params, void* script)
{
    Handle_0012FA80 h = Make_0012FA80(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
    void* s;
    func_001E7C80(params, 0, &s, 1);
    Obj_0012FA80* o = h;
    if (o->m1C == 0x40D92263)
        return func_00128530(o, s, func_001E8708(params, 0x27E7A420), func_001E8708(params, 0xB8C08F55));
    if (o->m1C == 0x5200DFB6)
        return func_00126490(o, s);
    return false;
}
