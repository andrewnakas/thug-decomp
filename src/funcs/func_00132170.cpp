struct Obj_00132170;
extern "C" void func_001325A0(Obj_00132170* self);
extern "C" void func_00146240(Obj_00132170* self);

struct Obj_00132170 {
    int m0;
    void Shutdown();
};

void Obj_00132170::Shutdown() {
    func_001325A0(this);
    func_00146240(this);
}
