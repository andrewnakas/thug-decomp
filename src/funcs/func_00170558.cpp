class Obj_00170558 {
public:
    char pad[0x1C];
    unsigned int m_flags;
    bool GetBit14();
};

bool Obj_00170558::GetBit14()
{
    return (m_flags & 0x4000) != 0;
}
