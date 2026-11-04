struct Obj_0012B728;

extern "C" void func_00183C98(Obj_0012B728* o, void* h);
extern "C" void func_00183CB8(Obj_0012B728* o, void* h);

struct Handle_0012B728 {
    Obj_0012B728* m_obj;
    Handle_0012B728* m_prev;
    Handle_0012B728* m_next;
    Handle_0012B728(Obj_0012B728* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_0012B728()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012B728& operator=(Obj_0012B728* o)
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

struct Obj_0012B728 {
    char pad0[0x18];
    int m18;
};

struct C_0012B728 {
    char pad0[0x1A0];
    int m_sel;
    int m_selId;
    char pad1A8[0x1CC - 0x1A8];
    int m_wrap;
    int m1D0;
    void Move(int dir, int stay, int notify);
};

extern "C" int func_00124288(C_0012B728* self);
extern "C" Obj_0012B728* func_00124238(C_0012B728* self, int i);
extern "C" void func_00184078(Obj_0012B728* o, unsigned int id, int* out);
extern "C" int func_001840C8(Obj_0012B728* o, unsigned int id);
extern "C" int func_00125DC8(Obj_0012B728* o);
extern "C" void func_0012BA50(C_0012B728* self);

void C_0012B728::Move(int dir, int stay, int notify)
{
    int tries = func_00124288(this) * 2;
    if (m_sel < 0)
        m_sel = 0;
    while (tries) {
        if (!stay) {
            m_sel += dir;
            if (m_sel >= func_00124288(this)) {
                if (m_wrap)
                    m_sel = 0;
                else {
                    dir = -dir;
                    m_sel = func_00124288(this) - 1;
                }
            } else if (m_sel < 0) {
                if (m_wrap)
                    m_sel = func_00124288(this) - 1;
                else {
                    m_sel = 0;
                    dir = -dir;
                }
            }
        }
        stay = 0;
        Handle_0012B728 h((Handle_0012B728(func_00124238(this, m_sel))).m_obj);
        m_selId = h.m_obj->m18;
        if (notify) {
            m1D0 = -1;
            func_00184078(h.m_obj, 0x5B92F8DD, &m1D0);
        }
        if (!func_001840C8(h.m_obj, 0xF33A3321) && !func_00125DC8(h.m_obj))
            break;
        tries--;
    }
    if (tries) {
        func_0012BA50(this);
        return;
    }
    m_selId = 0;
    m_sel = -1;
}
