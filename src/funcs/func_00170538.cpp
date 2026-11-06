class Obj_00170538 {
public:
    char pad[0x1C];
    unsigned int m_flags;
    int GetBit0();
};

int Obj_00170538::GetBit0()
{
    return m_flags & 1;
}
