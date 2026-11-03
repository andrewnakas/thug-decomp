struct Obj_001F53C0 {
    char pad[0xa8];
    int m_state;
    void Reset();
};

void Obj_001F53C0::Reset()
{
    m_state = 0x1;
}
