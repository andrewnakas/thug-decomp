struct Obj_00200F80 {
    char pad[0x1838];
    int m_val;
    int Get() const;
};

int Obj_00200F80::Get() const
{
    return m_val;
}
