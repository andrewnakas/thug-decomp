struct Obj_00251DC8 {
    char m_pad[0x14C];
    float m_values[8];
    float Get(int i);
};

float Obj_00251DC8::Get(int i)
{
    return m_values[i];
}
