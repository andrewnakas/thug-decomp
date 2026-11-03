// Maps a bit depth (32/24/16/8/4) to a pixel-storage mode.
int PsmFromDepth0017EE98(int bits)
{
    switch (bits) {
    case 32:
        return 0;
    case 24:
        return 1;
    case 16:
        return 2;
    case 8:
        return 0x13;
    case 4:
        return 0x14;
    default:
        return 0;
    }
}
