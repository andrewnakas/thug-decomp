struct Obj_001A6BA8 {
    int m0[8];
    int m_flags;
    bool Test();
};

bool Obj_001A6BA8::Test()
{
    return (m_flags & 0x200) != 0;
}
