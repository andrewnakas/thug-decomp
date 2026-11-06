/* sym: __13Base_001D6708 = 0x001D4CC8 */
/* sym: __12Mem_001D6708 = 0x001022D8 */
/* sym: _vt$12Obj_001D6708 = 0x00363EF0 */

class Base_001D6708 {
public:
    int m0;
    int m4;
    int m8;
    Base_001D6708();
    virtual void V0();
};

class Mem_001D6708 {
public:
    int m0;
    Mem_001D6708();
};

extern "C" void func_001D6800(void* self, int a);

class Obj_001D6708 : public Base_001D6708 {
public:
    char pad10[0xB4 - 0x10];
    int mB4;
    char padB8[0xC0 - 0xB8];
    Mem_001D6708 mC0;
    Obj_001D6708(int a);
    virtual void V1();
};

Obj_001D6708::Obj_001D6708(int a)
{
    func_001D6800(this, a);
    mB4 = 1;
}
