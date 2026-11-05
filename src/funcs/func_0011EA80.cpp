struct Obj_0011EA80 {
    int m0[2];
    char* m_8;
    char* Get();
};

char* Obj_0011EA80::Get()
{
    if (m_8)
        return m_8 + 0x308;
    return 0;
}
