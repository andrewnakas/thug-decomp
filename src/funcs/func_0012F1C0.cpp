extern "C" void func_00183C98(void* p, void* ref);
extern "C" void func_00183CB8(void* p, void* ref);

struct Handle_0012F1C0 {
    void* p;
    int m4;
    int m8;
    ~Handle_0012F1C0()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
};

struct Ref_0012F1C0 {
    void* p;
    int m4;
    int m8;
    Ref_0012F1C0(const Handle_0012F1C0& o)
    {
        m4 = 0;
        m8 = 0;
        p = o.p;
        if (p) {
            func_00183C98(p, this);
        }
    }
    Ref_0012F1C0(const Ref_0012F1C0& o)
    {
        p = o.p;
        m4 = 0;
        m8 = 0;
        if (p) {
            func_00183C98(p, this);
        }
    }
    ~Ref_0012F1C0()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
    Ref_0012F1C0& operator=(const Ref_0012F1C0& o)
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
        p = o.p;
        if (p) {
            func_00183C98(p, this);
        }
        return *this;
    }
};

struct Obj_0012F1C0;
extern "C" Handle_0012F1C0 func_0012DB48(Obj_0012F1C0* self, int id, int a);

struct Obj_0012F1C0 {
    char pad[0x4C];
    Ref_0012F1C0 m_cur;
    void Select(int id);
};

void Obj_0012F1C0::Select(int id)
{
    Ref_0012F1C0 r = func_0012DB48(this, id, 1);
    m_cur = r;
}
