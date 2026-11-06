/* sym: _$_13Base_0014A9F0 = 0x0013AD70 */
/* sym: _vt$12Obj_0014A9F0 = 0x0035F358 */
extern "C" void func_0010A8D8(void* heap, void* p);
extern void* D_00388A70;

class Base_0014A9F0 {
public:
    int m_pad[5];
    virtual void Update();
    virtual ~Base_0014A9F0();
};

class Obj_0014A9F0 : public Base_0014A9F0 {
public:
    void* m18;
    virtual void Update();
    virtual ~Obj_0014A9F0();
};

Obj_0014A9F0::~Obj_0014A9F0()
{
    if (m18)
        func_0010A8D8(D_00388A70, m18);
}
