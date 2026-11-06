class Obj_00170568 {
public:
    char pad[0x1C];
    int m_flags;
    bool Test();
};

bool Obj_00170568::Test()
{
    return (m_flags & 0x200) != 0;
}
