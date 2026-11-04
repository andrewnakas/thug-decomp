struct Inner_0025EC70 {
    char m_pad[0xB64];
    int m_value;
};

struct Obj_0025EC70 {
    char m_pad[0x3C];
    Inner_0025EC70* m_inner;
    int Get();
};

int Obj_0025EC70::Get()
{
    if (!m_inner)
        return 0;
    return m_inner->m_value;
}
