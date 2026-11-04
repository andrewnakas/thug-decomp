struct Ui_002C6B80;

extern "C" Ui_002C6B80* func_00253A30(int v);
extern "C" void func_00253A80();
extern "C" void func_00253F08(Ui_002C6B80* p, int v);

struct Ref_002C6B80 {
    int m0;
    Ui_002C6B80* m4;
    Ref_002C6B80(Ui_002C6B80* p) { m4 = p; }
};

class Ctx_002C6B80 {
public:
    int m0;
    Ref_002C6B80 m4;
    Ctx_002C6B80() : m4(func_00253A30(0)) {}
    Ref_002C6B80* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_002C6B80() { func_00253A80(); }
};

struct Obj_002C6B80 {
    char pad0[0xAC];
    unsigned int mAC;
    int mB0;
    void Refresh();
};

void Obj_002C6B80::Refresh()
{
    Ctx_002C6B80 ctx;
    if (mAC == 0x7ECA21E5 && mB0 == 0) {
        func_00253F08(ctx.GetRef()->m4, 0);
    } else {
        func_00253F08(ctx.GetRef()->m4, 1);
    }
}
