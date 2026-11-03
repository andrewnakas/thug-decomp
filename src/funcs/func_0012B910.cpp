struct Obj_0012B910;
struct Handle_0012B910;

extern "C" void func_00183C98(Obj_0012B910* o, Handle_0012B910* h);
extern "C" void func_00183CB8(Obj_0012B910* o, Handle_0012B910* h);

struct Handle_0012B910 {
    Obj_0012B910* m_obj;
    Handle_0012B910* m_prev;
    Handle_0012B910* m_next;
    Handle_0012B910(const Handle_0012B910& h)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = h.m_obj;
        if (m_obj)
            func_00183C98(m_obj, this);
    }
    ~Handle_0012B910()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    operator Obj_0012B910*() const { return m_obj; }
};

class Struct1E6978 {
public:
    int m_w[4];
    Struct1E6978();
    ~Struct1E6978();
};

extern "C" Handle_0012B910 func_0012DB48(void* mgr, int id, int a);
extern "C" void func_00184078(Obj_0012B910* o, unsigned int id, int* out);
extern "C" void func_00189750(void* mgr, unsigned int type, int target, unsigned int id, Struct1E6978* s, int a);
extern "C" void func_001E7268(Struct1E6978* s, char* name, int v);

extern void* D_0038C7B0;
extern void* D_00389A30;
extern char D_0035CF78[];
extern char D_0035CF88[];

struct C_0012B910 {
    char pad[0x1A4];
    int m1A4;
    char pad1A8[4];
    int m1AC;
    void Stop(int a);
};

extern "C" void func_0012B728(C_0012B910* o, int a, int b, int c);

static inline Obj_0012B910* Find(int id)
{
    return func_0012DB48(D_00389A30, id, 0);
}

void C_0012B910::Stop(int a)
{
    void* mgr = D_0038C7B0;
    int val = -1;
    if (m1A4) {
        Obj_0012B910* o = Find(m1A4);
        if (o)
            func_00184078(o, 0x8321DD71, &val);
        func_00189750(mgr, 0x4ADF0CD3, m1A4, 0x36B2EE74, 0, 0);
    }
    func_0012B728(this, a, 0, 1);
    if (m1A4) {
        Struct1E6978 s;
        func_001E7268(&s, D_0035CF78, m1AC);
        if (val != -1)
            func_001E7268(&s, D_0035CF88, val);
        func_00189750(mgr, 0x9D3FB516, m1A4, 0x36B2EE74, &s, 0);
    }
}
