extern "C" void func_00164860(int type, void* p, short a, short b, short c);

struct Obj_00173110 {
    char pad0[0x148];
    void* m148;
    void* m14C;
    char pad150[0x154 - 0x150];
    short m154;
    short m156;
    void Fn();
};

void Obj_00173110::Fn()
{
    func_00164860(0x50, m148, m154, -1, -1);
    if (m14C)
        func_00164860(0x50, m14C, m156, -1, -1);
}
