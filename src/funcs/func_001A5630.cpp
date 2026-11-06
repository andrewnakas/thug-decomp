struct Obj_001A5630 {
    char pad[0x1C];
    int m1C;
    bool Test();
};

bool Obj_001A5630::Test()
{
    return (m1C & 0x27) != 0;
}
