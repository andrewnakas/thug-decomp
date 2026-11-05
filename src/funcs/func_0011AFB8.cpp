/* sym: __13Base_0011AFB8 = 0x0011AB88 */
/* sym: _vt$12Obj_0011AFB8 = 0x0035C9A8 */
struct Info_0011AFB8 {
    char pad[0x44];
    int m44;
};

extern "C" void* func_001321A0();
extern "C" void func_00144CB0(void* p, int a);
extern "C" void* func_0011AC30(void* self);
extern "C" Info_0011AFB8* func_00185578(void* p, unsigned int name);

class Base_0011AFB8 {
public:
    char pad[0x14];
    Base_0011AFB8();
    virtual ~Base_0011AFB8();
};

class Obj_0011AFB8 : public Base_0011AFB8 {
public:
    int m18;
    int m1C;
    int m20;
    int m24;
    int m28;
    int m2C;
    void* m30;
    int m34;
    Obj_0011AFB8();
    virtual void Run();
};

Obj_0011AFB8::Obj_0011AFB8()
{
    m2C = 0;
    m18 = 0;
    m1C = 0;
    m20 = 0;
    m24 = 0;
    m28 = 0;
    m30 = func_001321A0();
    func_00144CB0(m30, 0);
    m34 = func_00185578(func_0011AC30(this), 0x72AD7B23)->m44;
}
