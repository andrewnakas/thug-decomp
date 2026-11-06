extern "C" void func_001E6B30(void* self);
extern "C" void func_001E6A50(void* self, void* other);

struct Obj_001E6A00 {
    int m0;
    Obj_001E6A00& operator=(const Obj_001E6A00& o);
};

Obj_001E6A00& Obj_001E6A00::operator=(const Obj_001E6A00& o)
{
    if (&o == this)
        return *this;
    func_001E6B30(this);
    func_001E6A50(this, (void*)&o);
    return *this;
}
