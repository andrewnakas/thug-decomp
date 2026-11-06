class Obj_00172688 {
public:
    char pad[0x60];
    unsigned int m_flags;
    void SetFlag(int on);
};

void Obj_00172688::SetFlag(int on)
{
    if (on)
        m_flags |= 2;
    else
        m_flags &= ~2;
}
