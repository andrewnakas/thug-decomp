struct Obj_001FA608 {
    char pad[0x180];
    int m_val;
    int* Get();
};

int* Obj_001FA608::Get()
{
    return &m_val;
}
