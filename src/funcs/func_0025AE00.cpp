extern "C" void func_001180E8(void* p);

struct Obj_0025AE00 {
    char pad[0x3C];
    void* m3C;
    bool Fn();
};

bool Obj_0025AE00::Fn()
{
    if (m3C) func_001180E8(m3C);
    return true;
}
