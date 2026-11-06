/* sym: _$_13Base_0012AEB8 = 0x001238D0 */
/* sym: _vt$13Elem_0012AEB8 = 0x0035CF10 */
extern "C" void func_0013AEB8(void* w);

class Base_0012AEB8 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual ~Base_0012AEB8();
};

class Elem_0012AEB8 : public Base_0012AEB8 {
public:
    char padC[0x1A0 - 0xC];
    void* m_window;
    virtual void V0();
    virtual ~Elem_0012AEB8();
};

Elem_0012AEB8::~Elem_0012AEB8()
{
    func_0013AEB8(m_window);
}
