/* sym: __13Base_0012C0B8 = 0x0012AF08 */
/* sym: _vt$13Elem_0012C0B8 = 0x0035CF98 */
class Root_0012C0B8 {
public:
    int m0;
    int m4;
    virtual void V0();
};

class Base_0012C0B8 : public Root_0012C0B8 {
public:
    char padC[0x1B8 - 0xC];
    int m_mode;
    Base_0012C0B8();
    virtual void V0();
};

class Elem_0012C0B8;
extern "C" void func_00183F08(Elem_0012C0B8* self, unsigned int type);

class Elem_0012C0B8 : public Base_0012C0B8 {
public:
    Elem_0012C0B8();
    virtual void V0();
};

Elem_0012C0B8::Elem_0012C0B8()
{
    m_mode = 0;
    func_00183F08(this, 0xCCDED1E1);
}
