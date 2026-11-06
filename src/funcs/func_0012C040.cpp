/* sym: __13Base_0012C040 = 0x0012AF08 */
/* sym: _vt$13Elem_0012C040 = 0x0035D000 */
class Root_0012C040 {
public:
    int m0;
    int m4;
    virtual void V0();
};

class Base_0012C040 : public Root_0012C040 {
public:
    char padC[0x1B8 - 0xC];
    int m_mode;
    Base_0012C040();
    virtual void V0();
};

class Elem_0012C040;
extern "C" void func_00183F08(Elem_0012C040* self, unsigned int type);

class Elem_0012C040 : public Base_0012C040 {
public:
    Elem_0012C040();
    virtual void V0();
};

Elem_0012C040::Elem_0012C040()
{
    m_mode = 1;
    func_00183F08(this, 0x130EF802);
}
