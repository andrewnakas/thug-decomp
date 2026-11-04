extern int* D_00393EA4;
extern int* D_00393EA8;
extern int* D_00393EAC;

extern "C" void func_00105948(int p)
{
    int q;
    if (D_00393EAC[p] == 0x1000) {
        return;
    }
    if (D_00393EA8[p] == 0x1000) {
        q = D_00393EA4[p];
    } else if (D_00393EA4[p] == 0x1000) {
        q = D_00393EA8[p];
    } else {
        q = D_00393EA4[p];
        if (D_00393EA8[q] != 0x1000) {
            do {
                q = D_00393EA8[q];
            } while (D_00393EA8[q] != 0x1000);
            D_00393EA8[D_00393EAC[q]] = D_00393EA4[q];
            D_00393EAC[D_00393EA4[q]] = D_00393EAC[q];
            D_00393EA4[q] = D_00393EA4[p];
            D_00393EAC[D_00393EA4[p]] = q;
        }
        D_00393EA8[q] = D_00393EA8[p];
        D_00393EAC[D_00393EA8[p]] = q;
    }
    D_00393EAC[q] = D_00393EAC[p];
    if (D_00393EA8[D_00393EAC[p]] == p) {
        D_00393EA8[D_00393EAC[p]] = q;
    } else {
        D_00393EA4[D_00393EAC[p]] = q;
    }
    D_00393EAC[p] = 0x1000;
}
