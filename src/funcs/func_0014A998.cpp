/* sym: __13Base_0014A998iiii = 0x0013AD48 */
/* sym: _vt$12Obj_0014A998 = 0x0035F358 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

class Base_0014A998 {
public:
    int m_pad[5];
    Base_0014A998(int a, int b, int c, int d);
    virtual void Update();
    virtual ~Base_0014A998();
};

class Obj_0014A998;
extern "C" void func_0014AA48(Obj_0014A998* self);

class Obj_0014A998 : public Base_0014A998 {
public:
    void* m18;
    Obj_0014A998(int a, int b, int c, int d);
    virtual void Update();
    virtual ~Obj_0014A998();
};

Obj_0014A998::Obj_0014A998(int a, int b, int c, int d) : Base_0014A998(a, b, c, d)
{
    m18 = func_0010A638(D_00388A70, 8, 1, 0);
    func_0014AA48(this);
}
