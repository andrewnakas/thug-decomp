struct Obj_001FA610 {
    char pad[0x190];
    int m_val;
    int* Get();
};

int* Obj_001FA610::Get()
{
    return &m_val;
}
