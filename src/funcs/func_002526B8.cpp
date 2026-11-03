struct Obj_002526B8 {
    char pad[0x10];
    int m_val;
    int* Get();
};

int* Obj_002526B8::Get()
{
    return &m_val;
}
