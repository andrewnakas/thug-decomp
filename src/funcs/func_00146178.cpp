extern "C" void* func_0014C1B8(void* self);
extern "C" void func_00170BF0(void* p);
extern "C" void func_0010DCD0(void* self);

struct Obj_00146178 {
    int Unload();
};

int Obj_00146178::Unload()
{
    void* v = func_0014C1B8(this);
    if (v) {
        func_00170BF0(v);
        func_0010DCD0(this);
    }
    return 1;
}
