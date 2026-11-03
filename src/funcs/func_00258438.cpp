struct Obj_00258438 {
    int m_pad[65];
    int m_flags;
    int m_pad2[18];
    int m_150;
    void Set();
};

void Obj_00258438::Set()
{
    m_150 = 1;
    m_flags |= 1;
}
