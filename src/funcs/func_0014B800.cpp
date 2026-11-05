struct Obj_0014B800 {
    int m0[7];
    unsigned int* m_1C;
    bool GetChannel(int i);
};

bool Obj_0014B800::GetChannel(int i)
{
    int mask = 2 << i;
    return (*m_1C & mask) != 0;
}
