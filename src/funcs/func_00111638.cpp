struct Obj_00111638 {
    char pad[0x3C];
    int m_3C;
    char pad2[0x100];
    int m_140;
    int m_144;
    int m_148;
    int m_14C;
    void Reset();
};

void Obj_00111638::Reset()
{
    m_3C = -1;
    m_140 = 0;
    m_144 = 0;
    m_148 = 0;
    m_14C = 0;
}
