extern void* D_0038FC78;
extern "C" void func_002C8FA0(void* p, bool b);
extern "C" void func_002CC178(void* p);
extern "C" void* func_002CC830();
extern "C" void func_0022E2E8(void* p);
extern "C" void func_002C0E60(void* p, int a, int b);
extern "C" void func_002C6B80(void* self);
extern "C" void func_002C4ED0(void* self, int on);

struct Ui_002C4D98 {
    char pad0[0x40];
    int m40;
    int m44;
};

extern "C" Ui_002C4D98* func_00253A30(int v);
extern "C" void func_00253A80();

struct Ref_002C4D98 {
    int m0;
    Ui_002C4D98* m4;
    Ref_002C4D98(Ui_002C4D98* p) { m4 = p; }
    Ui_002C4D98* Get() { return m4; }
};

class Ctx_002C4D98 {
public:
    int m0;
    Ref_002C4D98 m4;
    Ctx_002C4D98() : m4(func_00253A30(0)) {}
    virtual void Dummy();
    virtual ~Ctx_002C4D98() { func_00253A80(); }
};

struct Obj_002C4D98 {
    char pad0[0x60];
    int m60;
    char pad64[0x1C];
    void* m80;
    char pad84[0x1C];
    void* mA0;
    char padA4[0x8];
    unsigned int mAC;
    void Enter(unsigned int mode);
};

void Obj_002C4D98::Enter(unsigned int mode)
{
    if (mode) mAC = mode;
    m60 = 0;
    if (mA0) func_002C8FA0(mA0, mAC == 0x7ECA21E5);
    if (mode == 0xA40F0B8A || mode == 0xCD3682C1) {
        func_002C4ED0(this, 0);
        func_002CC178(func_002CC830());
    } else {
        func_002C4ED0(this, 1);
    }
    Ctx_002C4D98 ctx;
    Ref_002C4D98* r = &ctx.m4;
    if (mode == 0x7ECA21E5) {
        func_0022E2E8(D_0038FC78);
        Ui_002C4D98* ui = r->m4;
        ui->m40 = 0x140;
        ui->m44 = 100;
        func_002C0E60(m80, 0, 0);
    } else {
        Ui_002C4D98* ui = r->m4;
        ui->m40 = 0x140;
        ui->m44 = 50;
    }
    func_002C6B80(this);
}
