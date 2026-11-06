class Obj_00172658 {
public:
    char pad[0x60];
    unsigned m_flags;
    void SetFlag(int on);
};

void Obj_00172658::SetFlag(int on)
{
    if (on) m_flags |= 1;
    else m_flags &= ~1;
}
