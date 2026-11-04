/* sym: __13Base_00278870 = 0x00184DC0 */
/* sym: _vt$13Comp_00278870 = 0x00376A80 */
/* sym: __11EA_00278870 = 0x00279F10 */
/* sym: __11EB_00278870 = 0x00279F70 */
extern "C" void* func_003315B8(void* p, int c, int n);

struct Base_00278870 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00278870();
    virtual ~Base_00278870();
};

struct EA_00278870 {
    char m[0x90];
    EA_00278870();
};

struct EB_00278870 {
    char m[0x5C];
    EB_00278870();
};

struct Comp_00278870 : Base_00278870 {
    int m1C;
    EA_00278870 mA[20];
    int mB60;
    EB_00278870 mB[20];
    int m1294;
    Comp_00278870();
    virtual void Update();
    virtual ~Comp_00278870();
};

Comp_00278870::Comp_00278870()
{
    m_type = 0x18223FD6;
    m1294 = 0;
    m1C = 0;
    mB60 = 0;
    func_003315B8(mA, 0, sizeof(mA));
    func_003315B8(mB, 0, sizeof(mB));
}
