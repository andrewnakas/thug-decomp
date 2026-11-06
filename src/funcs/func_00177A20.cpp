struct Rec_00177A20 {
    int m_0;
    int m_4;
};

extern Rec_00177A20** D_0038BF84;

void Set_00177A20(int i, int v)
{
    if (D_0038BF84) {
        Rec_00177A20* r = D_0038BF84[i];
        if (r)
            r->m_4 = v;
    }
}
