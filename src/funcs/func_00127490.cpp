struct Obj_00127490;

extern "C" void func_00183C98(Obj_00127490* o, void* h);
extern "C" void func_00183CB8(Obj_00127490* o, void* h);

struct Handle_00127490 {
    Obj_00127490* m_obj;
    Handle_00127490* m_prev;
    Handle_00127490* m_next;
    Handle_00127490(Obj_00127490* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_00127490(const Handle_00127490& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_00127490()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00127490& operator=(Obj_00127490* o)
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

struct Obj_00127490 {
    char pad0[0x60];
    Obj_00127490* m60;
    char pad64[0x18C - 0x64];
    float m18C;
    char pad190[0x1B8 - 0x190];
    void* m1B8;
};

struct Info_00127490 {
    float m0;
    float m4;
    float m8;
    float mC;
    float m10;
    float m14;
};

struct Base_00127490 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
};

struct C_00127490 : public Base_00127490 {
    char padC[0x54 - 0xC];
    Obj_00127490* m54;
    char pad58[0x18C - 0x58];
    float m18C;
    char pad190[0x1D4 - 0x190];
    void* m1D4;
    void Layout(void* params);
};

extern "C" Info_00127490* func_001307E0(void* o, void* params, int* out);
extern "C" void func_001239D0(Obj_00127490* o, float* a, float* b);
extern "C" void func_00130730(void* o, Info_00127490* info, int x);
extern "C" void func_00124868(C_00127490* self, void* params);

void C_00127490::Layout(void* params)
{
    if (m1D4) {
        V10();
        int x;
        Info_00127490* info = func_001307E0(m1D4, params, &x);
        Handle_00127490 h(Handle_00127490(m54).m_obj);
        while (h.m_obj) {
            Info_00127490 i = *info;
            float a;
            float b;
            func_001239D0(h.m_obj, &a, &b);
            b += h.m_obj->m18C * 0.5f;
            float d = m18C * 0.5f - b;
            i.m14 += info->mC * d - d;
            func_00130730(h.m_obj->m1B8, &i, x);
            h = h.m_obj->m60;
        }
    }
    func_00124868(this, params);
}
