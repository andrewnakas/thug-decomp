struct Obj001A2CD0 {
    char pad[0x60];
    int m_val;
    int Get() const;
};

int Obj001A2CD0::Get() const
{
    return m_val;
}
