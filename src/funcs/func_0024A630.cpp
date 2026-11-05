struct Obj_0024A630 {
    char pad0[0xA4];
    int mA4;
    char padA8[0xB8 - 0xA8];
    int mB8;
    bool Idle();
};

bool Obj_0024A630::Idle()
{
    bool r = false;
    if (mB8) r = mA4 == 0;
    return r;
}
