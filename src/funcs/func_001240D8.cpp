class Obj_001240D8 {
public:
    int m0[3];
    unsigned int m_flags;
    void SetActive(int on);
};

void Obj_001240D8::SetActive(int on)
{
    if (on) {
        m_flags |= 0x20000;
    } else {
        m_flags &= ~0x20000;
        m_flags &= ~0x40000;
    }
}
