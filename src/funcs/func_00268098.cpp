/* sym: _vt$12Obj_00268098 = 0x00376118 */
/* sym: _$_13Base_00268098 = 0x00256980 */
extern "C" void func_002680F8(void* self);

struct Base_00268098 {
    int m0;
    int m4;
    virtual ~Base_00268098();
};

struct Obj_00268098 : Base_00268098 {
    char pad[0x168 - 0xC];
    int m168;
    virtual void Update();
    virtual ~Obj_00268098();
};

Obj_00268098::~Obj_00268098()
{
    func_002680F8(this);
    m168 = 0;
}
