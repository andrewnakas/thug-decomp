/* sym: _vt$12Obj_0011ECB8 = 0x0035CA68 */
extern float D_00389440[];

struct Base_0011ECB8 {
    int m0;
    int m4;
    char pad8[0x400];
    float m408;
    char pad40C[0x7C];
    int m488;
    int m48C;
    int m490;
    Base_0011ECB8()
    {
        m408 = D_00389440[0];
    }
};

class Obj_0011ECB8 : public Base_0011ECB8 {
public:
    Obj_0011ECB8();
    virtual ~Obj_0011ECB8();
};

Obj_0011ECB8::Obj_0011ECB8()
{
    m4 = 0;
    m490 = 0;
    m488 = 0;
    m48C = 0;
}
