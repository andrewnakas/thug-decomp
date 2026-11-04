struct FlagHolder {
    char pad[0x58];
    unsigned int m_flags;
    bool TestFlag(int bit) const;
};

bool FlagHolder::TestFlag(int bit) const
{
    return (m_flags & (1 << bit)) != 0;
}
