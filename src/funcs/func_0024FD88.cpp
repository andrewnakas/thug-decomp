/* sym: _$_12Scr_0024FD88 = 0x001EE4D8 */
/* sym: _vt$12Obj_0024FD88 = 0x003749A8 */
extern "C" void func_0010A8D8(void* pool, void* p);
extern void* D_00388A70;

struct Scr_0024FD88 {
    int m0;
    ~Scr_0024FD88();
};

struct Obj_0024FD88 {
    int m0;
    int m4;
    Scr_0024FD88* m8;
    char padC[8];
    Scr_0024FD88* m14;
    virtual void V0();
    virtual ~Obj_0024FD88();
    static void operator delete(void* p) { func_0010A8D8(D_00388A70, p); }
};

Obj_0024FD88::~Obj_0024FD88()
{
    delete m8;
    delete m14;
}
