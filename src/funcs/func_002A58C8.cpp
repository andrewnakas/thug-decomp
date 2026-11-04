struct Obj_002A58C8;
extern "C" void func_002A58F8(Obj_002A58C8* self);
extern "C" void func_002A3870(Obj_002A58C8* self);

struct Obj_002A58C8 {
    int m0;
    void Shutdown();
};

void Obj_002A58C8::Shutdown() {
    func_002A58F8(this);
    func_002A3870(this);
}
