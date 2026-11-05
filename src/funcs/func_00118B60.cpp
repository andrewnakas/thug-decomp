/* sym: __13Base_00118B60iii = 0x00118238 */
/* sym: _vt$12Obj_00118B60 = 0x0035C6B0 */
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* p, int a);

class Base_00118B60 {
public:
    char pad[0x14];
    Base_00118B60(int a, int b, int c);
    virtual ~Base_00118B60();
};

class Obj_00118B60 : public Base_00118B60 {
public:
    int m18;
    int m1C;
    int m20;
    void* m24;
    Obj_00118B60(int a, int b, int c);
    virtual void Run();
};

Obj_00118B60::Obj_00118B60(int a, int b, int c) : Base_00118B60(a, b, c)
{
    m20 = b;
    m24 = func_001E6978(func_001190D0(8));
    func_001E6AC8(m24, c);
}
