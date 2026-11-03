struct Obj_001D7348 {
    char pad[0x10];
    int m_val;
    int* Get();
};

int* Obj_001D7348::Get()
{
    return &m_val;
}
