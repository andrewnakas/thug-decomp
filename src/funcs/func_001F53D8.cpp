struct Obj_001F53D8 {
    char pad0[0xA8];
    int mA8;
    int Swap(int v);
};

int Obj_001F53D8::Swap(int v)
{
    int o = mA8;
    mA8 = v;
    return o;
}
