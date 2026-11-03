struct Obj_00128230;

extern "C" void func_00183C98(Obj_00128230* o, void* h);
extern "C" void func_00183CB8(Obj_00128230* o, void* h);

struct Handle_00128230 {
    Obj_00128230* m_obj;
    Handle_00128230* m_prev;
    Handle_00128230* m_next;
    Handle_00128230(Obj_00128230* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_00128230()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00128230& operator=(Obj_00128230* o)
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

struct Color_00128230 {
    unsigned char r, g, b, a;
};

struct Obj_00128230 {
    char pad0[0x60];
    Obj_00128230* m60;
    char pad64[0x18C - 0x64];
    float m18C;
};

struct C_00128230 {
    char pad0[0xC];
    unsigned int m_flags;
    char pad10[0x54 - 0x10];
    Obj_00128230* m54;
    char pad58[0xC8 - 0x58];
    Color_00128230 m_color;
    char padCC[0x188 - 0xCC];
    float m188;
    float m18C;
    char pad190[0x1BC - 0x190];
    float m1BC;
    float m1C0;
    float m1C4;
    float m1C8;
    float m1CC;
    int m1D0;
    void Refresh();
};

extern "C" void func_00123CD8(Obj_00128230* o, float a, float b);
extern "C" void func_00123FE0(Obj_00128230* o, const Color_00128230& c, int f);
extern "C" void func_00123A18(Obj_00128230* o, float a, float b, int f);
extern "C" void func_001283E0(C_00128230* self);

void C_00128230::Refresh()
{
    if (!(m_flags & 0x1000))
        return;
    float y = (m1C0 + 1.0f) * (m18C - m1CC) * 0.5f;
    Handle_00128230 h(Handle_00128230(m54).m_obj);
    for (int i = 0; i < m1D0; i++) {
        func_00123CD8(h.m_obj, m1BC, -1.0f);
        func_00123FE0(h.m_obj, Color_00128230(m_color), 1);
        func_00123A18(h.m_obj, (m1BC + 1.0f) * m188 * 0.5f, y, 0);
        y += h.m_obj->m18C * m1C4 * m1C8;
        h = h.m_obj->m60;
    }
    func_001283E0(this);
}
