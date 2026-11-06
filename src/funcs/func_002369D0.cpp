struct Obj_002369D0;
struct Handle_002369D0;

extern "C" void func_00183C98(Obj_002369D0* o, Handle_002369D0* h);
extern "C" void func_00183CB8(Obj_002369D0* o, Handle_002369D0* h);

struct Obj_002369D0 {
    char pad0[0x80];
    char m80[4];
};

struct Handle_002369D0 {
    Obj_002369D0* m_obj;
    Handle_002369D0* m_prev;
    Handle_002369D0* m_next;
    Handle_002369D0()
    {
        m_prev = 0;
        m_next = 0;
        m_obj = 0;
    }
    ~Handle_002369D0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_002369D0& operator=(const Handle_002369D0& h)
    {
        Obj_002369D0* o = h.m_obj;
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
    operator Obj_002369D0*() const { return m_obj; }
};

struct Color_002369D0 {
    unsigned char r, g, b, a;
};

extern void* D_0038FC78;
extern void* D_00389A30;

extern "C" float func_0010FAB8();
extern "C" void* func_0022DF08(void* net, int id);
extern "C" int func_002041F8(void* s);
extern "C" Handle_002369D0 func_0012DB48(void* mgr, unsigned int id, int a);
extern "C" float func_0012C130(void* p);
extern "C" void func_00123DB0(Obj_002369D0* o, int a, int b, float lo, float hi);
extern "C" void func_00123FE0(Obj_002369D0* o, const Color_002369D0& c, int f);
extern "C" float func_00340F60(float a);
extern "C" int func_002363D8(int v);

static inline int GetId_002369D0(int id)
{
    void* s = func_0022DF08(D_0038FC78, id);
    int r = 0;
    if (s)
        r = func_002041F8(s);
    return r;
}

struct Fade_002369D0 {
    short m0;
    short m2;
    int m4;
    int m_state;
    int mC;
    int m10;
    int m14;
    char pad18[0x68 - 0x18];
    int m68;
    int m6C;
    Color_002369D0 m70;
    Color_002369D0 m74;
    Color_002369D0 m78;
    float m7C;
    float m80;
    void Update();
};

extern "C" void func_0023AC30(Fade_002369D0* self, int a);
extern "C" void func_00236EC0(Fade_002369D0* self, int a);
extern "C" void func_00238EF8(Fade_002369D0* self, int a, int b);

void Fade_002369D0::Update()
{
    if (m68) {
        if (m6C)
            m68 -= func_0010FAB8() * 0.2f;
        else
            m68 -= func_0010FAB8() * 0.05f;
        if (m68 <= 0) {
            func_0023AC30(this, 0);
            m68 = 0;
        }
    }
    if (m_state == 1) {
        if (--m14 == 0) {
            func_00236EC0(this, GetId_002369D0(m2));
            m_state = 2;
        }
    } else if (m_state == 2) {
        func_00238EF8(this, m10, 0);
        m10 -= func_002363D8(m10);
        if (m10 < 0) {
            m10 = 0;
            m_state = 0;
        }
    }
    void* m = D_00389A30;
    Handle_002369D0 h;
    void* s = func_0022DF08(D_0038FC78, m2);
    if (s)
        h = func_0012DB48(m, func_002041F8(s) + 0xFE1DC544, 0);
    else
        h = func_0012DB48(m, 0xFE1DC544, 0);
    float t = m68 * 0.00033333333f;
    if (t > 1.0f)
        t = 1.0f;
    else if (t < 0.0f)
        t = 0.0f;
    func_00123DB0(h, 0, 0, t, func_0012C130(h.m_obj->m80));
    Color_002369D0 c = m70;
    if (m6C) {
        float k = (func_00340F60(m7C) + 1.0f) * 0.5f;
        m7C += m80;
        c.r = m74.r + (m78.r - m74.r) * k;
        c.g = m74.g + (m78.g - m74.g) * k;
        c.b = m74.b + (m78.b - m74.b) * k;
        c.a = m74.a + (m78.a - m74.a) * k;
    }
    func_00123FE0(h.m_obj, Color_002369D0(c), 1);
}
