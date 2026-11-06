/* sym: __13Base_0014C0A0i = 0x00132B40 */
/* sym: _vt$13Scrn_0014C0A0 = 0x0035F4E8 */
class Base_0014C0A0 {
public:
    char pad[0x280];
    Base_0014C0A0(int n);
    virtual ~Base_0014C0A0();
};

class Scrn_0014C0A0 : public Base_0014C0A0 {
public:
    char pad284[0xC];
    void* m290;
    void* m294;
    void* m298;
    Scrn_0014C0A0();
    virtual void V1();
    virtual ~Scrn_0014C0A0();
};

Scrn_0014C0A0::Scrn_0014C0A0() : Base_0014C0A0(10)
{
    m290 = 0;
    m294 = 0;
    m298 = 0;
}
