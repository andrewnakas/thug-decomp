extern "C" int func_00263560(unsigned int bits);

struct Set_00263A80 {
    int m0;
    unsigned int m_bits[7];
};

struct Obj_00263A80 {
    Set_00263A80 m_a[21];
    char pad[0x5C4 - 0x2A0];
    int m_set;
    int Count(int set);
};

int Obj_00263A80::Count(int set)
{
    if (set == -1)
        set = m_set;
    return func_00263560(m_a[set].m_bits[0]) + func_00263560(m_a[set].m_bits[1]);
}
