struct Obj_002012A0 {
    char pad[0x227c];
    int m_flags;
    bool Test() const;
};

bool Obj_002012A0::Test() const
{
    if (m_flags & 0x10)
        return true;
    return false;
}
