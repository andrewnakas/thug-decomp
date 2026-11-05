struct In_0014A548 {
    char pad[0x15C];
    int m_15C[16];
};

struct Obj_0014A548 {
    int m0[2];
    In_0014A548* m_8;
    void Set(int* v);
};

void Obj_0014A548::Set(int* v)
{
    for (int i = 0; i < 16; i++)
        m_8->m_15C[i] = *v++;
}
