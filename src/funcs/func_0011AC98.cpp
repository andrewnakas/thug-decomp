/* sym: __13Base_0011AC98 = 0x0011AB88 */
/* sym: _vt$12Obj_0011AC98 = 0x0035C9E8 */
struct Info_0011AC98 {
    char pad[0x44];
    int m44;
};

extern "C" void* func_001321A0();
extern "C" void func_00144CB0(void* p, int a);
extern "C" void* func_0011AC30(void* self);
extern "C" Info_0011AC98* func_00185578(void* p, unsigned int name);

class Base_0011AC98 {
public:
    char pad[0x14];
    Base_0011AC98();
    virtual ~Base_0011AC98();
};

class Obj_0011AC98 : public Base_0011AC98 {
public:
    void* m18;
    int m1C;
    Obj_0011AC98();
    virtual void Run();
};

Obj_0011AC98::Obj_0011AC98()
{
    m18 = func_001321A0();
    func_00144CB0(m18, 0);
    m1C = func_00185578(func_0011AC30(this), 0x72AD7B23)->m44;
}
