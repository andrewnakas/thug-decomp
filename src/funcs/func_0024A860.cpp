struct Obj_0024A860 {
    char pad0[0xA4];
    int mA4;
    char padA8[0xB8 - 0xA8];
    int mB8;
    int mBC;
    int mC0;
    int mC4;
    int mC8;
    void Reset();
};

void Obj_0024A860::Reset()
{
    mA4 = 0;
    mC0 = 0;
    mB8 = 0;
    mBC = 0;
    mC4 = 0;
    mC8 = 0;
}
