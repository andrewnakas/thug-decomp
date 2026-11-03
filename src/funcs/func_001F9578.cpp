struct Obj_001F9578 {
    char pad[0x1008];
    int m_arr[1];
    int Get(int i);
};

int Obj_001F9578::Get(int i)
{
    return m_arr[i];
}
