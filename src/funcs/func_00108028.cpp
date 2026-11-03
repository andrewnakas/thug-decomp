extern unsigned char D_00395550[];

void func_00108028(const unsigned char* in, unsigned char* out, int len)
{
    int i, j, k, r, c;
    unsigned int flags;
    if ((unsigned int)len > 0x1FFFFFF) {
        for (;;) {
        }
    }
    for (i = 0; i < 0xFEE; i++)
        D_00395550[i] = ' ';
    r = 0xFEE;
    flags = 0;
    for (;;) {
        flags >>= 1;
        if (!(flags & 0x100)) {
            if (len == 0)
                break;
            len--;
            c = *in++;
            flags = c | 0xFF00;
        }
        if (flags & 1) {
            if (len == 0)
                break;
            len--;
            c = *in++;
            *out++ = c;
            D_00395550[r++] = c;
            r &= 0xFFF;
        } else {
            if (len == 0)
                break;
            len -= 2;
            i = *in++;
            j = *in++;
            i |= (j & 0xF0) << 4;
            j = (j & 0xF) + 2;
            for (k = 0; k <= j; k++) {
                c = D_00395550[(i + k) & 0xFFF];
                *out++ = c;
                D_00395550[r++] = c;
                r &= 0xFFF;
            }
        }
    }
}
