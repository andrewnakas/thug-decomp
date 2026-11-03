struct Obj_00263938 {
    char m_pad[0x61C];
    int m_flags[4];
    void Set(int i);
};

void Obj_00263938::Set(int i)
{
    m_flags[i] = 1;
}
