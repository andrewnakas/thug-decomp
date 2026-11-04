extern int D_00360B30[][8];

int PsmLookup00165900(void* p, int x, int y, int psm)
{
    switch (psm) {
    case 0:
    case 1:
    case 0x13:
        return D_00360B30[y][x];
    case 2:
    case 0x14:
        return D_00360B30[x][y];
    default:
        return -1;
    }
}
