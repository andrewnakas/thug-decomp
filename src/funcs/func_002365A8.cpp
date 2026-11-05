/* sym: _$_14ListB_002365A8 = 0x0023AFA0 */
/* sym: _$_14ListA_002365A8 = 0x0023AEE8 */
struct ListA_002365A8 {
    char pad[0x18];
    ~ListA_002365A8();
};

struct ListB_002365A8 {
    char pad[0x18];
    ~ListB_002365A8();
};

extern void* D_00388A70;
extern "C" void func_0010A8D8(void* heap, void* p);
extern "C" void func_002381E0(void* self);

struct Obj_002365A8 {
    char pad[0x2C];
    ListA_002365A8 m_2C;
    ListB_002365A8 m_44;
    ~Obj_002365A8();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_002365A8::~Obj_002365A8()
{
    func_002381E0(this);
}
