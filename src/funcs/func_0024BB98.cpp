struct Obj_0024BB98 {
    char pad0[0x54];
    int m54;
    char pad58[0x48];
    int mA0;
    bool Fn();
};

bool Obj_0024BB98::Fn()
{
    if (mA0 == 0 && m54 <= 0) return true;
    return false;
}
