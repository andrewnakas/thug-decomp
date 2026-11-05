struct Obj00168558 {
    char pad[0xb0];
    int m_val;
    int* Get();
};

int* Obj00168558::Get()
{
    return &m_val;
}
