extern "C" void func_001E4F20(void* self);

struct Obj_001E4EF8 {
    Obj_001E4EF8* Init();
};

Obj_001E4EF8* Obj_001E4EF8::Init()
{
    func_001E4F20(this);
    return this;
}
