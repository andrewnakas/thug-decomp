extern "C" void func_00118158(void* p, int x, int k);

struct Obj_0025AE30 {
    char pad[0x18];
    int m18;
    char pad1C[0x20];
    void* m3C;
    bool Fn(int k);
};

bool Obj_0025AE30::Fn(int k)
{
    if (m3C) func_00118158(m3C, m18, k);
    return true;
}
