struct Obj119870 {
    char pad[0x2C];
    int m_state;
    bool InRange() const;
};

bool Obj119870::InRange() const
{
    return (unsigned int)(m_state - 1) < 2;
}
