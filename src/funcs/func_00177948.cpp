class Obj_00177948 {
public:
    int m_0;
    unsigned m_flags;
    void SetFlag(int on);
};

void Obj_00177948::SetFlag(int on)
{
    if (on) m_flags |= 0x10000;
    else m_flags &= ~0x10000;
}
