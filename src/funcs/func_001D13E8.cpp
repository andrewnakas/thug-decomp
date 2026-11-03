struct Obj_001D13E8 {
    void Release();
};

extern "C" void func_001D0FC8(Obj_001D13E8* self);

void Obj_001D13E8::Release()
{
    func_001D0FC8(this);
}
