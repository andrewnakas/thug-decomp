struct Ref_001EE4D8;

extern "C" void func_00183CB8(void* p, Ref_001EE4D8* ref);

struct Ref_001EE4D8 {
    void* m_p;
    void Release()
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
    }
};

struct Child_001EE4D8 {
    char pad0[8];
    int m_8;
    char padC[4];
    int m_10;
};

struct Node_001EE4D8 {
    char pad0[4];
    Node_001EE4D8* m_prev;
    Node_001EE4D8* m_next;
    char padC[0xB0];
    Ref_001EE4D8 m_BC;
    char padC0[0x18];
    void* m_D8;
    Child_001EE4D8* m_DC;
    char padE0[8];
    char m_E8[4];
};

extern Node_001EE4D8* D_0038E7D8;
extern int D_0038E7DC;

extern "C" void func_001EE9E0(Node_001EE4D8* self);
extern "C" void func_001E6AE8(void* p, int flags);
extern "C" void func_001EC910(Node_001EE4D8* self);
extern "C" void func_001EEB60(Node_001EE4D8* self);
extern "C" void func_00187EE0(Child_001EE4D8* p, int flags);
extern "C" void func_00183C08(void* p, int flags);
extern "C" void func_001219B0(void* p);

static inline void Delete_001EE4D8(Child_001EE4D8* c)
{
    if (c)
        func_00187EE0(c, 3);
}

void func_001EE4D8(Node_001EE4D8* self, int flags)
{
    func_001EE9E0(self);
    if (self->m_D8)
        func_001E6AE8(self->m_D8, 3);
    if (!self->m_next)
        D_0038E7D8 = self->m_prev;
    if (self->m_prev)
        self->m_prev->m_next = self->m_next;
    if (self->m_next)
        self->m_next->m_prev = self->m_prev;
    func_001EC910(self);
    if (self->m_DC) {
        func_001EEB60(self);
        Child_001EE4D8* c = self->m_DC;
        if (c->m_10)
            c->m_8 = 0;
        else
            Delete_001EE4D8(c);
    }
    D_0038E7DC--;
    func_00183C08(self->m_E8, 2);
    self->m_BC.Release();
    if (flags & 1)
        func_001219B0(self);
}
