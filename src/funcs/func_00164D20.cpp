extern unsigned int D_003942DC;
extern unsigned int D_003942E0;

extern "C" unsigned char* func_00164D20(unsigned char* p)
{
    if ((p[3] & 0x60) != 0x60) {
        switch (p[3] & 0x7F) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 16:
        case 17:
        case 19:
        case 20:
        case 21:
        case 23:
            return p + 4;
        case 1:
            D_003942E0 = p[0];
            D_003942DC = p[1];
            return p + 4;
        case 32:
            return p + 8;
        case 48:
        case 49:
            return p + 0x14;
        case 74:
            return p + p[2] * 8 + 4;
        case 80:
        case 81:
            return p + *(unsigned short*)p * 16 + 4;
        default:
            return p;
        }
    }
    int vn = (((unsigned long)p[3] >> 2) & 3) + 1;
    int vl = p[3] & 3;
    unsigned int wl = D_003942DC;
    unsigned int cl = D_003942E0;
    int bits = 32 >> vl;
    unsigned int num = p[2];
    if (cl >= wl) {
        return p + (((bits * vn * num + 31) >> 5) * 4 + 4);
    }
    unsigned int q = num / wl;
    unsigned int r = num % wl;
    return p + (((bits * vn * (cl * q + (cl < r ? cl : r)) + 31) >> 5) * 4 + 4);
}
