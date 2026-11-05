struct Obj_0024B510 {
    char pad0[0x8C];
    int m8C;
    char pad90[0xA4 - 0x90];
    int mA4;
    void Reset();
};

void Obj_0024B510::Reset()
{
    mA4 = 0;
    m8C = 0;
}
