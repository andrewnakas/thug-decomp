/* sym: __13Base_0011CFC0 = 0x0011AB88 */
/* sym: _vt$12Obj_0011CFC0 = 0x0035C828 */
struct Info_0011CFC0 {
    char pad[0x44];
    int m44;
};

extern "C" void* func_001321A0();
extern "C" void func_00144CB0(void* p, int a);
extern "C" void* func_0011AC30(void* self);
extern "C" Info_0011CFC0* func_00185578(void* p, unsigned int name);
extern "C" void* func_001046B0(int size);
extern "C" void* func_00119690(void* p);

class Base_0011CFC0 {
public:
    char pad[0x14];
    Base_0011CFC0();
    virtual ~Base_0011CFC0();
};

class Obj_0011CFC0 : public Base_0011CFC0 {
public:
    void* m18;
    void* m1C;
    int m20;
    Obj_0011CFC0();
    virtual void Run();
};

Obj_0011CFC0::Obj_0011CFC0()
{
    m1C = func_001321A0();
    func_00144CB0(m1C, 0);
    m20 = func_00185578(func_0011AC30(this), 0x72AD7B23)->m44;
    m18 = func_00119690(func_001046B0(0x38));
}
