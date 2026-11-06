/* sym: _$_13Base_0011B038 = 0x0011ABA8 */
/* sym: _vt$13Comp_0011B038 = 0x0035C9A8 */
extern "C" void func_001321C0(void* p);

struct Base_0011B038 {
    int m0[5];
    virtual void V0();
    virtual ~Base_0011B038();
};

struct Comp_0011B038 : Base_0011B038 {
    char pad18[0x30 - 0x18];
    void* m_res;
    virtual void V0();
    virtual ~Comp_0011B038();
};

Comp_0011B038::~Comp_0011B038()
{
    if (m_res) {
        func_001321C0(m_res);
        m_res = 0;
    }
}
