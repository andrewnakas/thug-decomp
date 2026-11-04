struct Obj_0012D310;
struct Handle_0012D310;

extern "C" void func_00183C98(Obj_0012D310* o, Handle_0012D310* h);
extern "C" void func_00183CB8(Obj_0012D310* o, Handle_0012D310* h);

struct Obj_0012D310 {
    int m0;
    int m4;
    virtual void V0();
    virtual void Load(void* params);
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void Init(void* params);
};

struct Handle_0012D310 {
    Obj_0012D310* m_obj;
    Handle_0012D310* m_prev;
    Handle_0012D310* m_next;
    Handle_0012D310(Obj_0012D310* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012D310(const Handle_0012D310& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012D310()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012D310& operator=(Obj_0012D310* o)
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
    Obj_0012D310* operator->() const { return m_obj; }
    operator Obj_0012D310*() const { return m_obj; }
};

static inline Handle_0012D310 Make_0012D310(const Handle_0012D310& t)
{
    return t;
}

struct Mgr_0012D310 {
    char pad0[0xD8];
    int m_D8;
    int m_DC;
    int m_E0;
    int m_E4;
    int m_E8;
    int m_EC;
    int m_F0;
    int m_F4;
    char padF8[0x104 - 0xF8];
    int m_104;
    int m_108;
    char pad10C[0x11C - 0x10C];
    int m_11C;
    int m_120;
    int m_124;
    char pad128[0x148 - 0x128];
    int m_148[16];
    int m_188[(0x3EC - 0x188) / 4];
    int m_3EC;
};

extern Mgr_0012D310* D_00388A70;
extern char D_00389A38[];
extern char D_00389A40[];
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int req);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" void func_0010A950(Mgr_0012D310* m, int heap);
extern "C" void func_0010A9B0(Mgr_0012D310* m);
extern "C" void* func_001046B0(int size);
extern "C" void func_00183E90(Obj_0012D310* o, int id);
extern "C" Obj_0012D310* func_00125C28(void* mem);
extern "C" Obj_0012D310* func_00125F10(void* mem);
extern "C" Obj_0012D310* func_0012C040(void* mem);
extern "C" Obj_0012D310* func_0012C0B8(void* mem);
extern "C" Obj_0012D310* func_00127000(void* mem);
extern "C" Obj_0012D310* func_00128680(void* mem);
extern "C" Obj_0012D310* func_0012CEB8(void* mem);
extern "C" Obj_0012D310* func_0012CF30(void* mem);
extern "C" Obj_0012D310* func_00128F38(void* mem);
extern "C" Obj_0012D310* func_0012AE58(void* mem);

struct Elem_0012D310 {
    char pad0[0x2C];
    virtual void V0();
    virtual void AddChild(Obj_0012D310* o);
    Handle_0012D310 Create(unsigned int type, int id, void* params);
};

Handle_0012D310 Elem_0012D310::Create(unsigned int type, int id, void* params)
{
    Handle_0012D310 h = Make_0012D310(0);
    bool pushed = false;
    unsigned int heap;
    int idx = 0;
    if (func_001E84E8(params, D_00389A38, &heap, 0)) {
        switch (heap) {
        case 0x477FC6DE:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_D8);
            break;
        case 0xC80BF12D:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_DC);
            break;
        case 0xE37E78C5:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_EC);
            break;
        case 0x9F7B7843:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_F4);
            break;
        case 0x03C84A59:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_124);
            break;
        case 0x935AB858:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_11C);
            break;
        case 0x5B8AB877:
            func_001E7E58(params, D_00389A40, &idx, 0);
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_148[idx]);
            break;
        case 0xEABD217B:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_3EC);
            break;
        case 0x39FB63CC:
            func_001E7E58(params, D_00389A40, &idx, 0);
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_188[idx]);
            break;
        case 0xE3F81B18:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_104);
            break;
        case 0xBAA81175:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_108);
            break;
        case 0x1CA1FF20:
            break;
        default:
            pushed = true;
            func_0010A950(D_00388A70, D_00388A70->m_E4);
            break;
        }
    } else {
        pushed = true;
        func_0010A950(D_00388A70, D_00388A70->m_E4);
    }
    switch (type) {
    case 0x5B9DA842:
        h = func_00125C28(func_001046B0(0x1B0));
        break;
    case 0x5200DFB6:
        h = func_00125F10(func_001046B0(0x1E0));
        break;
    case 0x130EF802:
        h = func_0012C040(func_001046B0(0x1E0));
        break;
    case 0xCCDED1E1:
        h = func_0012C0B8(func_001046B0(0x1E0));
        break;
    case 0x40D92263:
        h = func_00127000(func_001046B0(0x200));
        break;
    case 0xB12B510A:
        h = func_00128680(func_001046B0(0x1B0));
        break;
    case 0x84298A3C:
        h = func_0012CEB8(func_001046B0(0x1F0));
        break;
    case 0x2900E3D0:
        h = func_0012CF30(func_001046B0(0x1F0));
        break;
    case 0x82C59D78:
        h = func_00128F38(func_001046B0(0x5B0));
        break;
    case 0xA13ADBB7:
        h = func_0012AE58(func_001046B0(0x1B0));
        break;
    }
    func_00183E90(h, id);
    AddChild(h);
    h->Load(params);
    h->Init(params);
    if (pushed) func_0010A9B0(D_00388A70);
    return h;
}
