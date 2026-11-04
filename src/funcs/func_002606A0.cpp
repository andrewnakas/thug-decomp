struct Obj_002606A0 {
    char m_pad[0x30];
    float m_cur;
    float m_34;
    float m_max;
    void Flush();
};

void Obj_002606A0::Flush()
{
    if (m_max < m_cur)
        m_max = m_cur;
    m_cur = 0.0f;
}
