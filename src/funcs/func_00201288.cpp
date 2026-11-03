struct Obj_00201288 {
    char pad[0x227c];
    int m_flags;
    bool Test() const;
};

bool Obj_00201288::Test() const
{
    if (m_flags & 0x8)
        return true;
    return false;
}
