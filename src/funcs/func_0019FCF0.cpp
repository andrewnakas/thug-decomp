extern void* D_00392068;

struct Ref_0019FCF0 {
    int m0;
};

extern "C" Ref_0019FCF0* func_002A39E0(void* mgr, int a);

struct Model_0019FCF0 {
    char pad0[0x18];
    void* m18;
};

struct Obj_0019FCF0 {
    char pad0[0xC];
    Model_0019FCF0* mC;
    void Fn();
};

extern "C" bool func_001A2CE0(Obj_0019FCF0* self);
extern "C" void func_001A2610(Obj_0019FCF0* self, void* a, bool b, int c, int d);

void Obj_0019FCF0::Fn()
{
    Ref_0019FCF0* r = func_002A39E0(D_00392068, 0);
    void* m = mC->m18;
    func_001A2610(this, m, !func_001A2CE0(this), r->m0, 1);
}
