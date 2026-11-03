struct Obj_00258450 {
    int m_pad[65];
    int m_flags;
    int m_pad2[18];
    int m_150;
    void Clear();
};

void Obj_00258450::Clear()
{
    m_150 = 0;
    m_flags &= ~1;
}
