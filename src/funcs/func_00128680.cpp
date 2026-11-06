/* sym: __13Base_00128680 = 0x00123628 */
/* sym: _vt$13Elem_00128680 = 0x0035CDE8 */
class Base_00128680 {
public:
    int m0;
    int m4;
    Base_00128680();
    virtual void V0();
};

class Elem_00128680;
extern "C" void func_00183F08(Elem_00128680* self, unsigned int type);
extern "C" void* func_00131F48(int a);

class Elem_00128680 : public Base_00128680 {
public:
    char padC[0x1A0 - 0xC];
    int m1A0;
    void* m_sprite;
    Elem_00128680();
    virtual void V0();
};

Elem_00128680::Elem_00128680()
{
    m1A0 = 0;
    m_sprite = func_00131F48(0);
    func_00183F08(this, 0xB12B510A);
}
