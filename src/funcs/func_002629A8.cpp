struct Obj_002629A8 {
    char m_pad[0x1C];
    int m_items[2];
    int Get(int i);
};

int Obj_002629A8::Get(int i)
{
    return m_items[i];
}
