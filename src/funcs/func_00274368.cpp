/* sym: __13Base_00274368 = 0x00184DC0 */
/* sym: _vt$13Comp_00274368 = 0x00376888 */
typedef int qword __attribute__((mode(TI)));

struct Vec_00274368 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00274368() {}
    Vec_00274368(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00274368& operator=(const Vec_00274368& o) { q = o.q; return *this; }
};

struct Base_00274368 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_00274368();
    virtual ~Base_00274368();
};

struct Comp_00274368 : Base_00274368 {
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    Vec_00274368 m30;
    Vec_00274368 m40;
    Vec_00274368 m50[20];
    char pad190[0x110];
    int m2A0;
    int m2A4;
    int m2A8;
    int m2AC;
    int m2B0;
    int m2B4;
    int m2B8;
    int m2BC;
    int m2C0;
    int m2C4;
    Comp_00274368();
    virtual void Update();
    virtual ~Comp_00274368();
};

Comp_00274368::Comp_00274368()
{
    m_type = 0x850EEF66;
    m30 = Vec_00274368(0.0f, 0.0f, 0.0f, 1.0f);
    m40 = Vec_00274368(0.0f, 0.0f, 0.0f, 1.0f);
    m2AC = 0;
    m2B8 = 0;
    m2BC = 0;
    m2B0 = 0;
    m2B4 = 0;
    m2C0 = 0;
    m2C4 = 0;
    m28 = 0;
    m2A0 = 0;
    m24 = 0;
}
