class Elem_00125E10 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x48 - 0x10];
    Elem_00125E10* m_parent;
    bool Test();
};

bool Elem_00125E10::Test()
{
    if (!(m_flags & 0x400000)) {
        if (!m_parent || !m_parent->Test())
            return false;
    }
    return true;
}
