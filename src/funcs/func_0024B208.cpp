struct Obj_0024B208 {
    char pad0[0x90];
    int m90;
    int m94;
    int m98;
    char pad9C[0xA4 - 0x9C];
    int mA4;
    void Reset();
};

void Obj_0024B208::Reset()
{
    m90 = 0;
    mA4 = 0;
    m98 = 0;
}
