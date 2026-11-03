extern "C" void func_001F32B0(void* self);

struct Obj_001F32C0 {
    Obj_001F32C0* Init();
};

Obj_001F32C0* Obj_001F32C0::Init()
{
    func_001F32B0(this);
    return this;
}
