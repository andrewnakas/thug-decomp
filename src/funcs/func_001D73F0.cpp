struct Obj_001D73F0 {
    char pad[0x20];
    int m_val;
    int* Get();
};

int* Obj_001D73F0::Get()
{
    return &m_val;
}
