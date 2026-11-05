struct Obj_001F13F8 {
    char pad[0x1F4];
    int m1F4;
    void Set(int v);
};
extern "C" void func_001F1318(Obj_001F13F8* self);

void Obj_001F13F8::Set(int v)
{
    func_001F1318(this);
    m1F4 = v;
}
