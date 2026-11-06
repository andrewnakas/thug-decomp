/* sym: _$_13Base_0018E430 = 0x00184DD8 */
/* sym: _vt$12Der_0018E430 = 0x00361FE0 */
extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_001E6AE8(void* o, int n);

class Base_0018E430 {
public:
    char pad0[0x18];
    virtual void F();
    virtual ~Base_0018E430();
};

class Der_0018E430 : public Base_0018E430 {
public:
    char pad1C[0x50 - 0x1C];
    void* m50;
    char pad54[0x94 - 0x54];
    void* m94;
    void* m98;
    void* m9C;
    virtual void F();
    virtual ~Der_0018E430();
};

Der_0018E430::~Der_0018E430()
{
    if (m50)
        func_0010A8D8(D_00388A70, m50);
    if (m94)
        func_001E6AE8(m94, 3);
    if (m9C)
        func_001E6AE8(m9C, 3);
    if (m98)
        func_001E6AE8(m98, 3);
}
