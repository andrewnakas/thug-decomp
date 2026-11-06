/* sym: __13Base_001B6408 = 0x00184DC0 */
/* sym: _vt$12Obj_001B6408 = 0x00362BE0 */
struct Vec_001B6408 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Base_001B6408 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001B6408();
    virtual ~Base_001B6408();
};

struct Obj_001B6408 : Base_001B6408 {
    int m1C;
    Vec_001B6408 m20;
    Vec_001B6408 m30;
    unsigned int m40;
    Obj_001B6408();
    virtual void Update();
};

Obj_001B6408::Obj_001B6408()
{
    m_type = 0x8A897DD2;
    m1C = 0;
    m30.Set(0.0f, 1.0f, 0.0f, 1.0f);
    m40 = 0x806FFF30;
    m20.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
