/* sym: _$_13Base_00125F98 = 0x001238D0 */
/* sym: _vt$12Obj_00125F98 = 0x0035CD60 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

class Base_00125F98 {
public:
    int m0;
    int m4;
    virtual ~Base_00125F98();
};

class Obj_00125F98;
extern "C" void func_00126678(Obj_00125F98* self);
extern "C" void func_00126F28(Obj_00125F98* self, int a);

class Obj_00125F98 : public Base_00125F98 {
public:
    char padC[0x1A0 - 0xC];
    void* m1A0;
    virtual void Run();
    virtual ~Obj_00125F98();
};

Obj_00125F98::~Obj_00125F98()
{
    func_00126678(this);
    func_00126F28(this, 0);
    if (m1A0) {
        func_0010A8D8(D_00388A70, m1A0);
    }
}
