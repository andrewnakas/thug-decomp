struct Obj_0013B000 {
    int m0[6];
    int m_18;
};

extern int* D_0038A0E4;
extern Obj_0013B000* D_004653C0[];

int Get_0013B000(int i)
{
    int j = D_0038A0E4[i];
    if (j == -1)
        return 0;
    return D_004653C0[j]->m_18;
}
