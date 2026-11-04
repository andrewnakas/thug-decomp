struct Obj_00206918 {
    char pad[0x298];
    int m_val;
    int* Get();
};

int* Obj_00206918::Get()
{
    return &m_val;
}
