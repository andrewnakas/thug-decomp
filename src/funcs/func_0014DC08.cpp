struct Obj0014DC08 {
    char pad[0x60];
    int m_val;
    int* Get();
};

int* Obj0014DC08::Get()
{
    return &m_val;
}
