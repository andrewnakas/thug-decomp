struct Obj_001FA640 {
    char pad[0x13c];
    int m_val;
    int* Get();
};

int* Obj_001FA640::Get()
{
    return &m_val;
}
