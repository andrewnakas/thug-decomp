struct P_00165958 {
    int m_0;
    int m_4;
    int m_w;
    int m_h;
    int m_10;
};

extern int D_00360B30[4][8];
extern P_00165958 D_00360AE0[];
extern "C" int func_001657A0(int psm);

void BlockPos_00165958(int unused, int* x, int* y, int block, int psm)
{
    int row = -1;
    int col = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            if (D_00360B30[i][j] == block) {
                row = i;
                col = j;
                break;
            }
        }
    }
    P_00165958* p = &D_00360AE0[func_001657A0(psm)];
    switch (psm) {
    case 0:
    case 1:
    case 0x13:
        *x = col * p->m_w;
        *y = row * p->m_h;
        break;
    case 2:
    case 0x14:
        *x = row * p->m_w;
        *y = col * p->m_h;
        break;
    }
}
