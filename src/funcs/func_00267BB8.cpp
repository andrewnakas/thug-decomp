/* sym: __13Base_00267BB8 = 0x002568D8 */
/* sym: _vt$12Obj_00267BB8 = 0x003760A0 */
extern "C" void* func_001046B0(int size);
extern "C" void* func_001A4EE0(void* p);
extern "C" void func_00185288(void* self, void* p);

struct Base_00267BB8 {
    int m0;
    int m4;
    Base_00267BB8();
    virtual ~Base_00267BB8();
};

struct Obj_00267BB8 : Base_00267BB8 {
    char pad[0x1C - 0xC];
    int m1C;
    Obj_00267BB8();
    virtual void Update();
};

Obj_00267BB8::Obj_00267BB8()
{
    m1C = 3;
    func_00185288(this, func_001A4EE0(func_001046B0(0x4C)));
}
