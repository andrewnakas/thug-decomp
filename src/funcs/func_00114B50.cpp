extern "C" void func_00183CB8(void* ref, void** slot);

class Res_00114B50 {
public:
    int m0;
    int m4;
    virtual ~Res_00114B50();
};

struct Ref_00114B50 {
    Res_00114B50* m_p;
    Ref_00114B50& operator=(Res_00114B50* p)
    {
        if (m_p) {
            func_00183CB8(m_p, (void**)&m_p);
            m_p = 0;
        }
        m_p = p;
        return *this;
    }
    void Destroy()
    {
        delete m_p;
    }
};

struct Obj_00114B50 {
    char pad[0x14];
    unsigned int m_flags;
    Ref_00114B50 m_res;
    void Unload();
};

void Obj_00114B50::Unload()
{
    if (m_flags & 1) {
        m_res.Destroy();
        m_res = 0;
        m_flags &= ~1;
    }
}
