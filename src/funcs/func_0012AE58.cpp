/* sym: __13Base_0012AE58 = 0x00123628 */
/* sym: _vt$13Elem_0012AE58 = 0x0035CF10 */
class Base_0012AE58 {
public:
    int m0;
    int m4;
    Base_0012AE58();
    virtual void V0();
};

class Elem_0012AE58;
extern "C" void func_00183F08(Elem_0012AE58* self, unsigned int type);
extern "C" void* func_0013AE48(int x, int y, int w, int h);

class Elem_0012AE58 : public Base_0012AE58 {
public:
    char padC[0x1A0 - 0xC];
    void* m_window;
    Elem_0012AE58();
    virtual void V0();
};

Elem_0012AE58::Elem_0012AE58()
{
    func_00183F08(this, 0xA13ADBB7);
    m_window = func_0013AE48(0, 0, 0x280, 0x1C0);
}
