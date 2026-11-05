/* sym: __13Base_002701E0 = 0x00184DC0 */
/* sym: _vt$12Obj_002701E0 = 0x00376540 */
/* sym: __12Mem_002701E0 = 0x001DC540 */
struct Mem_002701E0 {
    int m0;
    Mem_002701E0();
    ~Mem_002701E0();
};

struct Base_002701E0 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_002701E0();
    virtual ~Base_002701E0();
};

struct Obj_002701E0 : Base_002701E0 {
    char pad1C[0x2C - 0x1C];
    Mem_002701E0 m2C;
    char pad30[0x54 - 0x30];
    int m54;
    char pad58[0x78 - 0x58];
    int m78;
    int m7C;
    int m80;
    int m84;
    int m88;
    int m8C;
    float m90;
    int m94;
    Obj_002701E0();
    virtual void Update();
};

Obj_002701E0::Obj_002701E0()
{
    m_type = 0xB5F1E9D2;
    m90 = 1.0f;
    m88 = 0;
    m84 = 0;
    m78 = 0;
    m7C = 1;
    m54 = 1;
    m80 = 0;
    m94 = 1;
}
