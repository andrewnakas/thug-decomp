class Obj_00170548 {
public:
    char pad[0x1C];
    int m_flags;
    bool Test();
};

bool Obj_00170548::Test()
{
    return (m_flags & 0x10) != 0;
}
