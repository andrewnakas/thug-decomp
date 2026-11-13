struct Obj_00125418;
struct Handle_00125418;

extern "C" void func_00183C98(Obj_00125418* o, Handle_00125418* h);
extern "C" void func_00183CB8(Obj_00125418* o, Handle_00125418* h);

struct Handle_00125418 {
    Obj_00125418* m_obj;
    Handle_00125418* m_prev;
    Handle_00125418* m_next;
    Handle_00125418(Obj_00125418* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    Handle_00125418(const Handle_00125418& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_00125418()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_00125418& operator=(Obj_00125418* o)
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
    Handle_00125418& operator=(const Handle_00125418& h)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
        return *this;
    }
    Obj_00125418* operator->() const { return m_obj; }
    operator Obj_00125418*() const { return m_obj; }
};

struct Obj_00125418 {
    char pad[0x48];
    Handle_00125418 m48;
    Handle_00125418 m54;
    Handle_00125418 m60;
    Handle_00125418 m6C;
    char pad78[0x194 - 0x78];
    float m194;
};


extern "C" void func_00125800(Obj_00125418* self, float f);

extern "C" void func_00125418(Obj_00125418* self, const Handle_00125418& parent)
{
    if (self->m48) {
        Handle_00125418 h(self->m48->m54);
        while (h) {
            if (h == self) {
                if (self->m6C)
                    self->m6C->m60 = self->m60.m_obj;
                else
                    self->m48->m54 = self->m60.m_obj;
                if (self->m60)
                    self->m60->m6C = self->m6C.m_obj;
                break;
            }
            h = h->m60.m_obj;
        }
    }
    self->m48 = parent.m_obj;
    if (self->m48) {
        Handle_00125418 h(Handle_00125418(self->m48->m54.m_obj).m_obj);
        if (h) {
            while (h->m60)
                h = h->m60.m_obj;
            h->m60 = self;
        } else {
            self->m48->m54 = self;
        }
        self->m6C = h;
    } else {
        self->m6C = 0;
    }
    self->m60 = 0;
    if (parent)
        func_00125800(self, parent->m194 + 1.0f);
    else
        func_00125800(self, 0.0f);
}
