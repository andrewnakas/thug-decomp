struct Obj_001D1818 {
    void Release();
};

extern "C" void func_001D0FC8(Obj_001D1818* self);

void Obj_001D1818::Release()
{
    func_001D0FC8(this);
}
