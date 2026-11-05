/* sym: _$_13Base_0011D040 = 0x0011ABA8 */
/* sym: _vt$12Obj_0011D040 = 0x0035C828 */
extern "C" void func_001321C0(void* p);

class Res_0011D040 {
public:
    char pad[0x14];
    virtual ~Res_0011D040();
};

class Base_0011D040 {
public:
    char pad[0x14];
    virtual ~Base_0011D040();
};

class Obj_0011D040 : public Base_0011D040 {
public:
    Res_0011D040* m18;
    void* m1C;
    int m20;
    virtual void Run();
    virtual ~Obj_0011D040();
};

Obj_0011D040::~Obj_0011D040()
{
    if (m1C) {
        func_001321C0(m1C);
        m1C = 0;
    }
    if (m18) {
        delete m18;
        m18 = 0;
    }
}
