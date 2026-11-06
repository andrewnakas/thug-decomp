/* sym: __13Base_0012AF08 = 0x00123628 */
/* sym: _vt$12Obj_0012AF08 = 0x0035D068 */
class Base_0012AF08 {
public:
    int m0;
    int m4;
    Base_0012AF08();
    virtual ~Base_0012AF08();
};

class Obj_0012AF08 : public Base_0012AF08 {
public:
    char padC[0x1A0 - 0xC];
    int m1A0;
    int m1A4;
    int m1A8;
    int m1AC;
    int m1B0;
    int m1B4;
    int m1B8;
    int m1BC;
    float m1C0;
    int m1C4;
    int m1C8;
    int m1CC;
    int m1D0;
    Obj_0012AF08();
    virtual void Run();
};

Obj_0012AF08::Obj_0012AF08()
{
    m1C0 = 1.0f;
    m1A0 = -1;
    m1A4 = 0;
    m1A8 = 0;
    m1AC = 0;
    m1BC = 0;
    m1C4 = 0;
    m1B0 = 0;
    m1B4 = 0;
    m1C8 = 1;
    m1CC = 1;
    m1D0 = -1;
}
