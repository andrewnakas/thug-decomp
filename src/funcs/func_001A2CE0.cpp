struct Obj_001A2CE0 {
    char pad[0x48];
    int m48;
    bool Test();
};

bool Obj_001A2CE0::Test()
{
    return (m48 & 0x20000000) != 0;
}
