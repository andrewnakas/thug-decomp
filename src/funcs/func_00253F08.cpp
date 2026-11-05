/* sym: _vt$12Ctx_00253F08 = 0x00367278 */
struct Table_00253F08;

extern "C" Table_00253F08* func_00183098(int v);
extern "C" void func_001830E8();
extern "C" void func_001833F0(Table_00253F08* t, void* arg);

struct Ref_00253F08 {
    int m0;
    Table_00253F08* m4;
    Ref_00253F08(Table_00253F08* p) { m4 = p; }
};

class Ctx_00253F08 {
public:
    int m0;
    Ref_00253F08 m4;
    Ctx_00253F08() : m4(func_00183098(0)) {}
    Ref_00253F08* GetRef() { return &m4; }
    virtual void Dummy();
    virtual ~Ctx_00253F08() { func_001830E8(); }
};

struct Obj_00253F08 {
    void Fn(void* arg);
};

void Obj_00253F08::Fn(void* arg)
{
    Ctx_00253F08 ctx;
    func_001833F0(ctx.GetRef()->m4, arg);
}
