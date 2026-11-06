class Obj_0017EC18 {
public:
    int m_0;
    unsigned m_flags;
    char pad[0x48];
    int m_count;
    void Drop();
};

void Obj_0017EC18::Drop()
{
    if (--m_count == 0) m_flags &= ~2;
}
