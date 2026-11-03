struct Obj_001D1ED0 {
    void Release();
};

extern "C" void func_001D0FC8(Obj_001D1ED0* self);

void Obj_001D1ED0::Release()
{
    func_001D0FC8(this);
}
