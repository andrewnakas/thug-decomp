/* sym: _$_13Base_0011AD00 = 0x0011ABA8 */
/* sym: _vt$13Comp_0011AD00 = 0x0035C9E8 */
extern "C" void func_001321C0(void* p);

struct Base_0011AD00 {
    int m0[5];
    virtual void V0();
    virtual ~Base_0011AD00();
};

struct Comp_0011AD00 : Base_0011AD00 {
    void* m_res;
    virtual void V0();
    virtual ~Comp_0011AD00();
};

Comp_0011AD00::~Comp_0011AD00()
{
    if (m_res) {
        func_001321C0(m_res);
        m_res = 0;
    }
}
