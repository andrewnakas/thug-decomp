struct Obj_001D1600 {
    void Release();
};

extern "C" void func_001D0FC8(Obj_001D1600* self);

void Obj_001D1600::Release()
{
    func_001D0FC8(this);
}
