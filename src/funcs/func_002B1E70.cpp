struct Mgr_002B1E70;
struct Obj_002B1E70;
extern Mgr_002B1E70* D_00392068;
extern "C" int func_002B1FC8(Obj_002B1E70* o);
extern "C" Obj_002B1E70* func_002A49B0(Mgr_002B1E70* m);
extern "C" void func_002A4A58(Mgr_002B1E70* m, Obj_002B1E70* o);

struct Obj_002B1E70 {
    char pad0[0x18];
    int m18;
    void SetState(int v);
};

void Obj_002B1E70::SetState(int v)
{
    Mgr_002B1E70* m = D_00392068;
    m18 = v;
    if (!func_002B1FC8(this)) {
        Obj_002B1E70* cur = func_002A49B0(m);
        if (cur == this)
            func_002A4A58(m, cur);
    }
}
