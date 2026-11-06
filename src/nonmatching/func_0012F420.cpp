/* fuzzy: 86.0 */
struct Obj_0012F420;
struct Handle_0012F420;

extern "C" void func_00183C98(Obj_0012F420* o, Handle_0012F420* h);
extern "C" void func_00183CB8(Obj_0012F420* o, Handle_0012F420* h);

struct ObjBase_0012F420 {
    int m0;
    int m4;
    virtual ~ObjBase_0012F420();
    virtual void V1();
    virtual void Run(unsigned int name, int a, void* script);
};

struct Obj_0012F420 : ObjBase_0012F420 {
};

struct Handle_0012F420 {
    Obj_0012F420* m_obj;
    Handle_0012F420* m_prev;
    Handle_0012F420* m_next;
    Handle_0012F420(const Handle_0012F420& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012F420()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012F420& operator=(Obj_0012F420* o)
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
    Obj_0012F420* operator->() const { return m_obj; }
    operator Obj_0012F420*() const { return m_obj; }
};

static inline Handle_0012F420 Make_0012F420(const Handle_0012F420& t)
{
    return t;
}

struct Thing_0012F420 {
    char pad[0xBC];
    Handle_0012F420 mBC;
};

struct Node_0012F420 {
    char m0;
    char m1;
    unsigned char m2;
};

extern void* D_00389A30;
extern "C" Handle_0012F420 func_0012DC18(void* mgr, void* params, unsigned int name, int flag);
extern "C" int func_001E8A30(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, int* out, int req);
extern "C" Node_0012F420* func_001E5040(unsigned int value);
extern "C" Thing_0012F420* func_001F0750(unsigned int name, int a, int b, int c, int d,
                                         int e, int f, int g, int h, int i);
extern "C" int func_001EFDC0(Thing_0012F420* p);

static inline Handle_0012F420 Find_0012F420(void* params)
{
    return Make_0012F420(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
}

bool Cmd_0012F420(void* params, void* script)
{
    Handle_0012F420 h = Make_0012F420(func_0012DC18(D_00389A30, params, 0x40C698AF, 1));
    unsigned int name;
    func_001E8A30(params, 0, &name, 1);
    int b = 0;
    func_001E8398(params, 0x86068BD9, &b, 0);
    int c = 0;
    func_001E8180(params, 0x7031F10C, &c, 0);
    int d = 0;
    func_001E8180(params, 0xE6CF88C4, &d, 0);
    Node_0012F420* n = func_001E5040(name);
    if (n && n->m2 == 9) {
        h->Run(name, c, script);
    } else {
        Thing_0012F420* t = func_001F0750(name, c, b, d, -1, 0, 0, 0, 0, 0);
        if (t) {
            t->mBC = h.m_obj;
            func_001EFDC0(t);
        }
    }
    return true;
}
