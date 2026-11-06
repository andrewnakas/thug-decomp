extern "C" void func_00164860(int type, void* p, short a, short b, short c);

struct Obj_0017ED30 {
    char pad0[0x38];
    void* m38;
    void* m3C;
    char pad40[0x48 - 0x40];
    short m48;
    short m4A;
    void Fn();
};

void Obj_0017ED30::Fn()
{
    func_00164860(0x50, m38, m48, -1, -1);
    if (m3C)
        func_00164860(0x50, m3C, m4A, -1, -1);
}
