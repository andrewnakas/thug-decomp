struct Obj_00252150 {
    char m_pad[0x188];
    int m_id;
    bool Is(int id);
};

bool Obj_00252150::Is(int id)
{
    return id == m_id;
}
