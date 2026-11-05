extern "C" void func_00184E78(void* self, int on);
extern "C" void func_002708C0(void* self);

struct Obj_00270870 {
    char pad[0x7C];
    int m7C;
    void Enable(int on);
};

void Obj_00270870::Enable(int on)
{
    func_00184E78(this, on);
    if (on)
        func_002708C0(this);
    else
        m7C = 1;
}
