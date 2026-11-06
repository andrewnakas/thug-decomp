/* sym: _$_13Base_001A2F68 = 0x00184DD8 */
/* sym: _vt$12Der_001A2F68 = 0x00362400 */
extern void* D_0038E0A0;
extern "C" void func_001DCED0(void* mgr, void* obj);

class Base_001A2F68 {
public:
    char pad0[0x18];
    virtual void F();
    virtual ~Base_001A2F68();
};

class Der_001A2F68 : public Base_001A2F68 {
public:
    virtual void F();
    virtual ~Der_001A2F68();
};

Der_001A2F68::~Der_001A2F68()
{
    func_001DCED0(D_0038E0A0, this);
}
