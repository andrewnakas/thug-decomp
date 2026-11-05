struct Obj_0024BBC0;
extern "C" void func_00244E70(Obj_0024BBC0* self);

struct Obj_0024BBC0 {
    char pad0[0x54];
    int m54;
    char pad58[0x48];
    int mA0;
    bool Fn();
};

bool Obj_0024BBC0::Fn()
{
    if (mA0) return false;
    if (m54 > 0) return false;
    func_00244E70(this);
    return true;
}
