class Obj_00170518 {
public:
    char pad[0x1C];
    unsigned int m_flags;
    bool GetBit1();
};

bool Obj_00170518::GetBit1()
{
    return (m_flags & 2) != 0;
}
