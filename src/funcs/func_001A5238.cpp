/* sym: __13Base_001A5238 = 0x00184DC0 */
/* sym: _vt$12Obj_001A5238 = 0x003626E0 */
struct Obj_001A5238;
extern "C" void func_001A6810(Obj_001A5238* o);

struct Base_001A5238 {
    int m0;
    unsigned int m_type;
    int m_pad[4];
    Base_001A5238();
    virtual ~Base_001A5238();
};

struct Elem_001A5238 {
    float v[4];
    Elem_001A5238() {}
};

struct Obj_001A5238 : Base_001A5238 {
    char pad1C[4];
    Elem_001A5238 m20[3];
    Elem_001A5238 m50[3];
    int m80;
    Elem_001A5238 m84[3];
    Elem_001A5238 mB4[3];
    char padE4[0x120 - 0xE4];
    int m120;
    char pad124[0x21C - 0x124];
    int m21C;
    char pad220[0x290 - 0x220];
    Obj_001A5238();
    virtual void Update();
};

Obj_001A5238::Obj_001A5238()
{
    m_type = 0x0A015E17;
    m21C = 0;
    m120 = 0;
    m80 = 1;
    func_001A6810(this);
}
