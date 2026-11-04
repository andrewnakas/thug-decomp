struct FlagsObj {
    char pad[0x1C];
    int m_flags;
    void ClearFlag1();
};

void FlagsObj::ClearFlag1() { m_flags &= ~1; }
