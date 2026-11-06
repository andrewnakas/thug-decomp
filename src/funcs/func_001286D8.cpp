/* sym: _$_13Base_001286D8 = 0x001238D0 */
/* sym: _vt$13Elem_001286D8 = 0x0035CDE8 */
extern "C" void func_00131F68(void* p);

class Base_001286D8 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Base_001286D8();
};

class Elem_001286D8 : public Base_001286D8 {
public:
    char padC[0x1A4 - 0xC];
    void* m_sprite;
    virtual void V0();
    virtual ~Elem_001286D8();
};

Elem_001286D8::~Elem_001286D8()
{
    if (m_sprite) {
        func_00131F68(m_sprite);
    }
}
