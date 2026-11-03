struct Obj_00202778 {
    char pad[0x6c];
    int m_flags;
    bool Test() const;
};

bool Obj_00202778::Test() const
{
    if (m_flags & 0x2)
        return true;
    return false;
}
