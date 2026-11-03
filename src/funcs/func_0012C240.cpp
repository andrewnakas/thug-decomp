struct Obj_0012C240;

extern "C" void func_00183C98(Obj_0012C240* o, void* h);
extern "C" void func_00183CB8(Obj_0012C240* o, void* h);

struct Handle_0012C240 {
    Obj_0012C240* m_obj;
    Handle_0012C240* m_prev;
    Handle_0012C240* m_next;
    Handle_0012C240(Obj_0012C240* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_0012C240()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012C240& operator=(Obj_0012C240* o)
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

struct Pair_0012C240 {
    float a;
    float b;
};

struct C_0012C240 {
    char pad0[0x1BC];
    void* m1BC;
    char pad1C0[0x1C4 - 0x1C0];
    float m1C4;
    float m1C8;
    char pad1CC[0x1D0 - 0x1CC];
    int m1D0;
    float m1D4;
    float m1D8;
    int m1DC;
    float m1E0;
    void Init(void* params);
};

extern "C" void func_003315B8(void* p, int c, int n);
extern "C" int func_00125A10(C_0012C240* self, void* params, unsigned int id, float* a, float* b);
extern "C" int func_001E7DE8(void* params, unsigned int id, int* out, int req);
extern "C" bool func_001E8708(void* params, unsigned int id);
extern "C" Obj_0012C240* func_001241C0(void* o);
extern "C" void func_0012CD50(C_0012C240* self, const Handle_0012C240& h, float* a, float* b, float* c, float* d);
extern "C" void func_00124328(C_0012C240* self, void* params);

void C_0012C240::Init(void* params)
{
    Pair_0012C240 p;
    func_003315B8(&p, 0, 8);
    if (func_00125A10(this, params, 0x67E093E4, &p.a, &p.b)) {
        m1C4 = p.a;
        m1C8 = p.b;
    }
    int n;
    if (func_001E7DE8(params, 0x9020A1D1, &n, 0))
        m1D8 = n;
    func_001E7DE8(params, 0xC855511C, &m1DC, 0);
    if (func_001E8708(params, 0xED889E1F)) {
        m1D4 = 0.0f;
        m1D0 = 1;
    } else if (func_001E8708(params, 0xC3A894F6)) {
        Handle_0012C240 h((Handle_0012C240(func_001241C0(m1BC))).m_obj);
        float a;
        float b;
        float c;
        float d;
        func_0012CD50(this, h, &a, &b, &c, &d);
        m1D0 = 1;
        m1D4 = b + d - m1E0;
    } else if (func_001E8708(params, 0xA1F3B8BB))
        m1D0 = 1;
    func_00124328(this, params);
}
