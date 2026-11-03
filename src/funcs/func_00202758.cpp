struct Obj_00202758 {
    char pad[0x6c];
    int m_flags;
    bool Test() const;
};

bool Obj_00202758::Test() const
{
    if (m_flags & 0x4)
        return true;
    return false;
}
