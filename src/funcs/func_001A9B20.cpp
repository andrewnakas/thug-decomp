/* sym: __13Base_001A9B20 = 0x00184DC0 */
/* sym: _vt$12Obj_001A9B20 = 0x00362770 */
extern "C" float func_001E5318(unsigned int name, int req);

struct Base_001A9B20 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001A9B20();
    virtual ~Base_001A9B20();
};

struct Obj_001A9B20 : Base_001A9B20 {
    int m1C;
    float m20;
    float m24;
    char pad28[4];
    int m2C;
    char pad30[0x4C - 0x30];
    int m4C;
    Obj_001A9B20();
    virtual void Update();
};

Obj_001A9B20::Obj_001A9B20()
{
    m_type = 0xCE0CA665;
    float r = func_001E5318(0xAD501995, 0) * 12.0f;
    m1C = 1;
    m2C = 3;
    m4C = 3;
    m20 = r;
    m24 = r * r;
}
