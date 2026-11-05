extern "C" void func_001180E8(void* p);

struct Obj_0025B700 {
    char pad[0x78];
    void* m78;
    bool Fn();
};

bool Obj_0025B700::Fn()
{
    if (m78) func_001180E8(m78);
    return true;
}
