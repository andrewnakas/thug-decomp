/* sym: _vt$12Obj_001149B0 = 0x0035C438 */
extern "C" void func_00183CB8(void* ref, void** slot);
extern "C" void func_00183C98(void* ref, void** slot);

struct Ref_001149B0 {
    void* m_p;
    int m_a;
    int m_b;
    Ref_001149B0()
    {
        m_a = 0;
        m_b = 0;
        m_p = 0;
    }
    void operator=(void* p)
    {
        if (m_p) {
            func_00183CB8(m_p, &m_p);
            m_p = 0;
        }
        m_p = p;
        if (p) {
            func_00183C98(p, &m_p);
        }
    }
};

class Obj_001149B0 {
public:
    int m0;
    float m_x;
    float m_y;
    float m_w;
    float m_h;
    int m14;
    Ref_001149B0 m_ref;
    void SetRect(float x, float y, float w, float h)
    {
        m_x = x;
        m_y = y;
        m_w = w;
        m_h = h;
    }
    Obj_001149B0(Obj_001149B0* o, void* ref);
    virtual ~Obj_001149B0();
    virtual void Run();
};

Obj_001149B0::Obj_001149B0(Obj_001149B0* o, void* ref) : m_x(0.0f), m_y(0.0f), m_w(1.0f), m_h(1.0f), m14(0)
{
    if (o) {
        m_x = o->m_x;
        m_y = o->m_y;
        m_w = o->m_w;
        m_h = o->m_h;
    } else {
        SetRect(0.0f, 0.0f, 1.0f, 1.0f);
    }
    m_ref = ref;
}
