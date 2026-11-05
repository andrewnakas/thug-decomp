struct Obj_0010B088 {
    int m0;
    int m_4;
    char pad[0x7C];
    int m_84;
    int Get();
};

int Obj_0010B088::Get()
{
    if (m_84)
        return m_4;
    return 0;
}
