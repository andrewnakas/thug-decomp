extern int D_00354DD0[];

struct Obj_00252278 {
    char m_pad[0x438];
    int m_value;
    void Reset();
};

void Obj_00252278::Reset()
{
    m_value = D_00354DD0[0];
}
