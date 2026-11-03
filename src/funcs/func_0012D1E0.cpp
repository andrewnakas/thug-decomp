struct Obj_0012D1E0;
struct Handle_0012D1E0;

extern "C" void func_00183CB8(Obj_0012D1E0* o, Handle_0012D1E0* h);
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Handle_0012D1E0 {
    Obj_0012D1E0* m_obj;
    Handle_0012D1E0* m_prev;
    Handle_0012D1E0* m_next;
    ~Handle_0012D1E0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Elem_0012D1E0 {
    Handle_0012D1E0 m_handle;
    int mC;
    int m10;
    int m14;
    int m18;
};

struct N_00187800 {
    int m0;
    int m4;
    int m8;
    N_00187800* m_next;
    N_00187800* m_prev;
    virtual void V0();
    virtual ~N_00187800()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
};

struct B_00187800 {
    int m0;
    N_00187800 m_node;
    char pad1C[0x2C - 0x1C];
    virtual void V0();
    virtual ~B_00187800() {}
};

struct S_0012D050 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    virtual void V0();
    virtual ~S_0012D050();
};

struct D_0012D050 : B_00187800, S_0012D050 {
    Handle_0012D1E0 m4C;
    Handle_0012D1E0 m58;
    Elem_0012D1E0 m64[48];
    int m5A4[2];
    int m5AC[2];
    int m5B4[48];
    int m674;
    virtual void V0();
    virtual ~D_0012D050();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

D_0012D050::~D_0012D050()
{
}
