extern unsigned char* D_00393EA0;
extern int* D_00393EA4;
extern int* D_00393EA8;
extern int* D_00393EAC;
extern int D_00393E98;
extern int D_00393E9C;

extern "C" void func_00105770(int r)
{
    int i;
    int p;
    int cmp = 1;
    unsigned char* key = &D_00393EA0[r];
    p = 0x1001 + key[0];
    D_00393EA8[r] = D_00393EA4[r] = 0x1000;
    D_00393E9C = 0;
    for (;;) {
        if (cmp >= 0) {
            if (D_00393EA8[p] != 0x1000) {
                p = D_00393EA8[p];
            } else {
                D_00393EA8[p] = r;
                D_00393EAC[r] = p;
                return;
            }
        } else {
            if (D_00393EA4[p] != 0x1000) {
                p = D_00393EA4[p];
            } else {
                D_00393EA4[p] = r;
                D_00393EAC[r] = p;
                return;
            }
        }
        for (i = 1; i < 18; i++) {
            if ((cmp = key[i] - D_00393EA0[p + i]) != 0) {
                break;
            }
        }
        if (i > D_00393E9C) {
            D_00393E98 = p;
            if ((D_00393E9C = i) >= 18) {
                break;
            }
        }
    }
    D_00393EAC[r] = D_00393EAC[p];
    D_00393EA4[r] = D_00393EA4[p];
    D_00393EA8[r] = D_00393EA8[p];
    D_00393EAC[D_00393EA4[p]] = r;
    D_00393EAC[D_00393EA8[p]] = r;
    if (D_00393EA8[D_00393EAC[p]] == p) {
        D_00393EA8[D_00393EAC[p]] = r;
    } else {
        D_00393EA4[D_00393EAC[p]] = r;
    }
    D_00393EAC[p] = 0x1000;
}
