struct Obj_001F9588 {
    char pad[0xc08];
    int m_arr[1];
    int Get(int i);
};

int Obj_001F9588::Get(int i)
{
    return m_arr[i];
}
