extern unsigned char D_003943A0[];

extern "C" unsigned char* func_00105F10(unsigned char* src, unsigned char* dst, int len)
{
    int i;
    int j;
    int k;
    int r;
    int c;
    unsigned int flags;
    for (i = 0; i < 0xFEE; i++) {
        D_003943A0[i] = ' ';
    }
    r = 0xFEE;
    flags = 0;
    for (;;) {
        if (((flags >>= 1) & 256) == 0) {
            if (len == 0) {
                break;
            }
            len--;
            c = *src++;
            flags = c | 0xFF00;
        }
        if (flags & 1) {
            if (len == 0) {
                break;
            }
            len--;
            c = *src++;
            *dst++ = c;
            D_003943A0[r++] = c;
            r &= 0xFFF;
        } else {
            if (len == 0) {
                break;
            }
            len -= 2;
            i = *src++;
            j = *src++;
            i |= (j & 0xF0) << 4;
            j = (j & 0x0F) + 2;
            for (k = 0; k <= j; k++) {
                c = D_003943A0[(i + k) & 0xFFF];
                *dst++ = c;
                D_003943A0[r++] = c;
                r &= 0xFFF;
            }
        }
    }
    return dst;
}
