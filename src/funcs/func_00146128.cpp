extern "C" void* func_0010DAB0(void* name);
extern "C" void* func_00170AE8(void* p, int a);
extern "C" void func_0014C1D8(void* self, void* v);

struct Obj_00146128 {
    bool Load(void* name);
};

bool Obj_00146128::Load(void* name)
{
    void* v = func_00170AE8(func_0010DAB0(name), 1);
    func_0014C1D8(this, v);
    return v != 0;
}
