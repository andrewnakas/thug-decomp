/* sym: _vt$12Obj_00270258 = 0x00376540 */
/* sym: _$_13Base_00270258 = 0x00184DD8 */
/* sym: _$_12Mem_00270258 = 0x001DC578 */
extern "C" void func_002708C0(void* self);

struct Mem_00270258 {
    int m0;
    ~Mem_00270258();
};

struct Base_00270258 {
    int m_pad[6];
    virtual ~Base_00270258();
};

struct Obj_00270258 : Base_00270258 {
    char pad1C[0x2C - 0x1C];
    Mem_00270258 m2C;
    virtual void Update();
    virtual ~Obj_00270258();
};

Obj_00270258::~Obj_00270258()
{
    func_002708C0(this);
}
