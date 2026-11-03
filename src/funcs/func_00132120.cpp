struct Obj_00132120;
extern "C" void func_001325A0(Obj_00132120* self);
extern "C" void func_001461E0(Obj_00132120* self);

struct Obj_00132120 {
    int m0;
    void Shutdown();
};

void Obj_00132120::Shutdown() {
    func_001325A0(this);
    func_001461E0(this);
}
