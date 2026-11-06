/* sym: __13Base_00125C28 = 0x00123628 */
/* sym: _vt$13Elem_00125C28 = 0x0035CC28 */
class Base_00125C28 {
public:
    int m0;
    int m4;
    Base_00125C28();
    virtual void V0();
};

class Elem_00125C28;
extern "C" void func_00183F08(Elem_00125C28* self, unsigned int type);

class Elem_00125C28 : public Base_00125C28 {
public:
    char padC[0x1A0 - 0xC];
    int m_focusChild;
    Elem_00125C28();
    virtual void V0();
};

Elem_00125C28::Elem_00125C28()
{
    m_focusChild = 0;
    func_00183F08(this, 0x5B9DA842);
}
