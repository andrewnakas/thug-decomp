struct Obj_001F4838 {
    char pad0[0xA1C];
    int mA1C;
    int mA20;
    void Set(int v, int k);
};

void Obj_001F4838::Set(int v, int k)
{
    if (k != mA20) mA1C = v;
}
