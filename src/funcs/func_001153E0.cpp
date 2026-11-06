/* sym: _$_13Base_001153E0 = 0x00114F88 */
/* sym: _vt$12Obj_001153E0 = 0x0035C508 */
extern "C" void func_00132120(void* res);

struct Base_001153E0 {
    int m0;
    int m_type;
    virtual void V0();
    virtual ~Base_001153E0();
};

struct Obj_001153E0 : Base_001153E0 {
    void* m_res;
    float m_a;
    float m_b;
    virtual void V0();
    virtual ~Obj_001153E0();
};

Obj_001153E0::~Obj_001153E0()
{
    if (m_res) {
        func_00132120(m_res);
        m_res = 0;
    }
}
