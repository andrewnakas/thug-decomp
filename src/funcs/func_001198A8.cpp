struct Obj_001198A8 {
    int m0[10];
    int m_28;
    void Toggle();
};

void Obj_001198A8::Toggle()
{
    if (m_28 == 0)
        m_28 = -1;
    else
        m_28 = 0;
}
