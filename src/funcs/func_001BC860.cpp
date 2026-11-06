/* sym: __13Base_001BC860 = 0x00184DC0 */
/* sym: _vt$12Obj_001BC860 = 0x00363298 */
extern "C" int func_0010FC30();

struct Base_001BC860 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001BC860();
    virtual ~Base_001BC860();
};

struct Obj_001BC860 : Base_001BC860 {
    int m1C;
    int m20;
    char pad24[4];
    int m28;
    int m2C;
    Obj_001BC860();
    virtual void Update();
};

Obj_001BC860::Obj_001BC860()
{
    m_type = 0xA9DB601E;
    m1C = 0;
    m20 = 0;
    m2C = 0;
    m28 = func_0010FC30();
}
