struct In_00144D90 {
    int m0[2];
    int m_8;
};

struct Obj_00144D90 {
    int m0;
    In_00144D90* m_4;
    int Get();
};

int Obj_00144D90::Get()
{
    return m_4->m_8;
}
