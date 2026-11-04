extern "C" void func_001E6970(void* self);

struct Obj_001E6978 {
    Obj_001E6978* Init();
};

Obj_001E6978* Obj_001E6978::Init()
{
    func_001E6970(this);
    return this;
}
