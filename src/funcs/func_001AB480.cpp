extern char D_00362A48[];
extern "C" void func_001E6AE8(void* o, int n);

struct Obj_001AB480;
extern "C" void func_00184DD8(Obj_001AB480* o, int f);

struct Obj_001AB480 {
    char pad[0x18];
    void* m18;
    char pad1C[0xA6C - 0x1C];
    void* mA6C;
    void Destroy(int flags);
};

void Obj_001AB480::Destroy(int flags)
{
    m18 = D_00362A48;
    if (mA6C)
        func_001E6AE8(mA6C, 3);
    func_00184DD8(this, flags);
}
