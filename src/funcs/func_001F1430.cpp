struct Val_001F1430 {
    unsigned char m0;
    unsigned char m_type;
    char pad[6];
    union {
        int i;
        float f;
    } m8;
    int Get();
};

int Val_001F1430::Get()
{
    if (m_type == 1)
        return m8.i;
    if (m_type == 2)
        return m8.f != 0.0f;
    return 0;
}
