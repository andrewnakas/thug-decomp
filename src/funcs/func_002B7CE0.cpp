extern void* D_00388A70;
extern "C" void func_0010AFE0(void* pool, void* p);

struct Elem_002B7CE0 {
    char pad[0x8];
    Elem_002B7CE0* m_next;
    virtual void A();
    virtual ~Elem_002B7CE0();
};

struct Comp_002B7CE0 {
    char pad[0x18];
    virtual ~Comp_002B7CE0();
};

struct Obj_002B7CE0 {
    int m0;
    int m4;
    Elem_002B7CE0* m8;
    int mC;
    int m10;
    char pad[0x20 - 0x14];
    Comp_002B7CE0* m20;
    void* m24;
    void Clear();
};

extern "C" void func_002B83B8(Obj_002B7CE0* o, int keep);

void Obj_002B7CE0::Clear()
{
    if (m0 & 8)
        func_002B83B8(this, 0);
    Elem_002B7CE0* e = m8;
    while (e) {
        Elem_002B7CE0* next = e->m_next;
        if (e)
            delete e;
        e = next;
    }
    m8 = 0;
    m10--;
    m0 &= ~2;
    func_0010AFE0(D_00388A70, m24);
    if (m20)
        delete m20;
    m24 = 0;
    m20 = 0;
}
