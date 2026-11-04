struct Obj_0012C6F8;
struct Handle_0012C6F8;

extern "C" void func_00183C98(Obj_0012C6F8* o, Handle_0012C6F8* h);
extern "C" void func_00183CB8(Obj_0012C6F8* o, Handle_0012C6F8* h);

struct Obj_0012C6F8 {
    char pad[0x1C];
    unsigned int m1C;
    char pad20[0x40];
    Obj_0012C6F8* m60;
};

struct Handle_0012C6F8 {
    Obj_0012C6F8* m_obj;
    Handle_0012C6F8* m_prev;
    Handle_0012C6F8* m_next;
    Handle_0012C6F8(Obj_0012C6F8* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_0012C6F8(const Handle_0012C6F8& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012C6F8()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012C6F8& operator=(Obj_0012C6F8* o)
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
    Obj_0012C6F8* operator->() const { return m_obj; }
    operator Obj_0012C6F8*() const { return m_obj; }
};

static inline Handle_0012C6F8 Make_0012C6F8(const Handle_0012C6F8& t)
{
    return t;
}

extern "C" unsigned int func_001F0D78(const char* s);
extern "C" int func_0012B6F8(Obj_0012C6F8* o, float* out);
extern char D_003899C0[];
extern char D_003899C8[];

static inline bool Is_0012C6F8(unsigned int id, const char* name)
{
    return id == func_001F0D78(name);
}

struct C_0012C6F8 {
    char pad[0x54];
    Obj_0012C6F8* m54;
    char pad58[0x130];
    float m188;
    float m18C;
    char pad190[0x2C];
    Obj_0012C6F8* m1BC;
    char pad1C0[0x1C];
    int m1DC;
    float m1E0;
    float m1E4;
    int m1E8;
    void Select();
};

void C_0012C6F8::Select()
{
    Handle_0012C6F8 h = Make_0012C6F8(m54);
    while (h) {
        if ((Is_0012C6F8(h->m1C, D_003899C0) && m1E8) || (Is_0012C6F8(h->m1C, D_003899C8) && !m1E8))
            m1BC = h;
        h = h->m60;
    }
    float t = -1.0f;
    if (func_0012B6F8(m1BC, &t) && m1DC >= 0) {
        m1E4 = t;
        m1E0 = t * m1DC;
    } else {
        m1DC = -1;
        m1E0 = m1E8 ? m18C : m188;
    }
}
