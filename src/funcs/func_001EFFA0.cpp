struct Obj_001EFFA0 {
    char pad0[0x98];
    int m98;
    char pad9C[0xA4 - 0x9C];
    int mA4;
    void Set(int v);
};

void Obj_001EFFA0::Set(int v)
{
    m98 = v;
    mA4 = 10;
}
