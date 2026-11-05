/* sym: __13Base_00268048 = 0x002568D8 */
/* sym: _vt$12Obj_00268048 = 0x00376118 */
extern char D_00376108[];
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_00183E90(void* self, unsigned int name);

struct Base_00268048 {
    int m0;
    int m4;
    Base_00268048();
    virtual ~Base_00268048();
};

struct Obj_00268048 : Base_00268048 {
    char pad[0x168 - 0xC];
    int m168;
    Obj_00268048();
    virtual void Update();
};

Obj_00268048::Obj_00268048()
{
    func_00183E90(this, func_001F0D78(D_00376108));
    m168 = 0;
}
