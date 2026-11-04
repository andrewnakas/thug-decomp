struct Obj_002A58F8;
extern "C" void func_0029F5E8(Obj_002A58F8* self);
extern "C" void func_0029F6C8(Obj_002A58F8* self);

struct Obj_002A58F8 {
    int m0;
    void Cleanup();
};

void Obj_002A58F8::Cleanup() {
    func_0029F5E8(this);
    func_0029F6C8(this);
}
