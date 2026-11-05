struct Obj_00123430 {
    char pad[0x40];
    int m_40;
    int* Get();
};

int* Obj_00123430::Get()
{
    return &m_40;
}
