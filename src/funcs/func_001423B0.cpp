struct Obj001423B0 {
    char pad[0xc];
    float m_arr[1];
    void Set(float v, int i);
};

void Obj001423B0::Set(float v, int i)
{
    m_arr[i] = v;
}
