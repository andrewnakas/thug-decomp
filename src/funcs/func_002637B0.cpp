struct Obj_002637B0 {
    char m_pad[0x5C4];
    int m_current;
    int m_values[4];
    int Get(int i);
};

int Obj_002637B0::Get(int i)
{
    if (i == -1)
        i = m_current;
    return m_values[i];
}
