struct Obj_0012D050;
struct Handle_0012D050;

extern "C" void func_00183C98(Obj_0012D050* o, Handle_0012D050* h);
extern "C" void func_00183CB8(Obj_0012D050* o, Handle_0012D050* h);

struct Handle_0012D050 {
    Obj_0012D050* m_obj;
    Handle_0012D050* m_prev;
    Handle_0012D050* m_next;
    Handle_0012D050()
    {
        m_prev = 0;
        m_next = 0;
        m_obj = 0;
    }
    ~Handle_0012D050()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_0012D050& operator=(Obj_0012D050* o)
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

struct Elem_0012D050 {
    Handle_0012D050 m_handle;
    int mC;
    int m10;
    int m14;
    int m18;
};

struct B_00187748 {
    char pad[0x2C];
    B_00187748();
    virtual void V0();
};

struct S_0012D050 {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    S_0012D050();
    virtual void V0();
    void Reset(int a);
};

struct D_0012D050 : B_00187748, S_0012D050 {
    Handle_0012D050 m4C;
    Handle_0012D050 m58;
    Elem_0012D050 m64[48];
    int m5A4[2];
    int m5AC[2];
    int m5B4[48];
    int m674;
    D_0012D050();
    virtual void V0();
};

D_0012D050::D_0012D050()
{
    m4C = 0;
    m58 = 0;
    Reset(0);
    for (int i = 0; i < 2; i++) {
        m5A4[i] = 0;
        m5AC[i] = 0;
    }
    for (int i = 0; i < 48; i++) {
        m64[i].m_handle = 0;
        m64[i].m10 = 0;
    }
    m674 = 0;
    for (int i = 47; i >= 0; i--)
        m5B4[i] = 0;
}
