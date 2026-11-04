struct Obj_00262990 {
    char m_pad[0x1C];
    int m_items[2];
    int m_index;
    int GetCurrent();
};

int Obj_00262990::GetCurrent()
{
    return m_items[m_index];
}
