struct Obj_00263950 {
    char m_pad[0x61C];
    int m_flags[4];
    int Get(int i);
};

int Obj_00263950::Get(int i)
{
    return m_flags[i];
}
