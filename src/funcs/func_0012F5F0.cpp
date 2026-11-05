extern "C" void func_00183C98(void* p, void* ref);
extern "C" void func_00183CB8(void* p, void* ref);

struct Handle_0012F5F0 {
    void* p;
    int m4;
    int m8;
    ~Handle_0012F5F0()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
};

struct Ref_0012F5F0 {
    void* p;
    int m4;
    int m8;
    Ref_0012F5F0(const Handle_0012F5F0& o)
    {
        m4 = 0;
        m8 = 0;
        p = o.p;
        if (p) {
            func_00183C98(p, this);
        }
    }
    Ref_0012F5F0(const Ref_0012F5F0& o)
    {
        p = o.p;
        m4 = 0;
        m8 = 0;
        if (p) {
            func_00183C98(p, this);
        }
    }
    ~Ref_0012F5F0()
    {
        if (p) {
            func_00183CB8(p, this);
            p = 0;
        }
    }
    Ref_0012F5F0& operator=(const Ref_0012F5F0& o)
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

class Elem_0012F5F0 {
public:
    int m0;
    int m4;
    virtual void V1();
    virtual void Apply(void* params);
};

struct Mgr_0012F5F0;
extern Mgr_0012F5F0* D_00389A30;
extern "C" Handle_0012F5F0 func_0012DC18(Mgr_0012F5F0* mgr, void* params, unsigned int name, int a);

extern "C" int func_0012F5F0(void* params)
{
    Ref_0012F5F0 r = func_0012DC18(D_00389A30, params, 0x40C698AF, 1);
    ((Elem_0012F5F0*)r.p)->Apply(params);
    return 1;
}
