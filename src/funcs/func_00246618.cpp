struct Obj_00246618 {
    char pad[0x3C];
    unsigned int m_flags;
    bool IsSet(int bit) const;
};

bool Obj_00246618::IsSet(int bit) const
{
    return (m_flags & (1 << bit)) != 0;
}
