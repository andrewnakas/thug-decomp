extern char D_00376688[];
extern char D_00376720[];
extern char D_003766F0[];

struct Node_00270EB8 {
    int m_0;
    unsigned int m_key;
    int m_data;
    Node_00270EB8* m_next;
    Node_00270EB8* m_prev;
    void* m_vtbl;
    void Init(void* vtbl)
    {
        m_key = 0xFFFFFFFF;
        m_data = 0;
        m_next = this;
        m_prev = this;
        m_vtbl = vtbl;
    }
};

struct Comp_00270EB8 {
    char pad0[4];
    unsigned int m_type;
    char pad8[0x10];
    void* m_vtbl;
    Node_00270EB8 m_listA;
    Node_00270EB8 m_listB;
    char pad4C[8];
    int m_54;
    int m_58;
};

extern "C" Comp_00270EB8* func_00184DC0(Comp_00270EB8* self);

Comp_00270EB8* func_00270EB8(Comp_00270EB8* self)
{
    func_00184DC0(self);
    self->m_vtbl = D_00376688;
    self->m_listA.Init(D_00376720);
    self->m_listB.Init(D_003766F0);
    self->m_type = 0x11B4C67F;
    self->m_54 = 0;
    self->m_58 = 0;
    return self;
}
