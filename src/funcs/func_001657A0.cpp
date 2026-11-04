// Maps a pixel-storage mode (0/1 = 32/24-bit, 2 = 16-bit, 0x13 = 8-bit, 0x14 = 4-bit) to an index.
int PsmIndex001657A0(int psm)
{
    switch (psm) {
    case 0:
    case 1:
        return 0;
    case 2:
        return 1;
    case 0x13:
        return 2;
    case 0x14:
        return 3;
    default:
        return -1;
    }
}
