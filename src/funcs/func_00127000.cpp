/* sym: __13Base_00127000 = 0x00123628 */
/* sym: _vt$12Obj_00127000 = 0x0035CCF8 */
struct Col_00127000 {
    unsigned char r, g, b, a;
    void Set(unsigned char ar, unsigned char ag, unsigned char ab, unsigned char aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
};

class Base_00127000 {
public:
    int m0;
    int m4;
    Base_00127000();
    virtual ~Base_00127000();
};

class Obj_00127000;
extern "C" void func_00183F08(Obj_00127000* self, unsigned int name);

class Obj_00127000 : public Base_00127000 {
public:
    char padC[0x1A0 - 0xC];
    int m1A0;
    char pad1A4[0x1C4 - 0x1A4];
    float m1C4;
    float m1C8;
    int m1CC;
    int m1D0;
    int m1D4;
    int m1D8;
    int m1DC;
    int m1E0;
    int m1E4;
    Col_00127000 m_color;
    int m1EC;
    int m1F0;
    Obj_00127000();
    virtual void Run();
};

Obj_00127000::Obj_00127000()
{
    m_color.Set(0, 0, 0, 0x80);
    m1A0 = 0;
    m1CC = 0;
    m1D0 = 0;
    m1D4 = 0;
    m1DC = 0;
    m1EC = 0;
    m1F0 = 0;
    m1C4 = 1.0f;
    m1C8 = 1.0f;
    func_00183F08(this, 0x40D92263);
}
