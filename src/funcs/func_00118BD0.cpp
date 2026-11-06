/* sym: _$_12Prm_00118BD0 = 0x001E6AE8 */
/* sym: _vt$13Base_00118BD0 = 0x0035C700 */
/* sym: _vt$12Evt_00118BD0 = 0x0035C6B0 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Prm_00118BD0 {
    int m0;
    int m4;
    ~Prm_00118BD0();
};

struct Base_00118BD0 {
    int m0;
    Base_00118BD0* m4;
    int m8;
    Base_00118BD0* m_next;
    Base_00118BD0* m_prev;
    virtual void v0();
    virtual ~Base_00118BD0()
    {
        m_prev->m_next = m_next;
        m_next->m_prev = m_prev;
        m_next = this;
        m_prev = this;
    }
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

struct Evt_00118BD0 : Base_00118BD0 {
    int m18;
    int m1C;
    int m20;
    Prm_00118BD0* m_params;
    virtual void v0();
    virtual ~Evt_00118BD0();
};

Evt_00118BD0::~Evt_00118BD0()
{
    if (m_params) {
        delete m_params;
        m_params = 0;
    }
}
