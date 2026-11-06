/* sym: _$_13Base_0018B9A8 = 0x00184DD8 */
/* sym: _vt$12Der_0018B9A8 = 0x00361E18 */
extern "C" void func_00132120(void* p);

class Base_0018B9A8 {
public:
    char pad0[0x18];
    virtual void F();
    virtual ~Base_0018B9A8();
};

class Der_0018B9A8 : public Base_0018B9A8 {
public:
    char pad1C[0x260 - 0x1C];
    void* m260;
    virtual void F();
    virtual ~Der_0018B9A8();
};

Der_0018B9A8::~Der_0018B9A8()
{
    func_00132120(m260);
}
