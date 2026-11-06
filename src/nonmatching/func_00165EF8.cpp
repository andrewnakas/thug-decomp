/* fuzzy: 64.9 */
extern unsigned int D_0034DEF0[256];

static inline unsigned char Nibble_00165EF8(unsigned char* src, int a)
{
    int s = (a & 1) * 4;
    return (src[a >> 1] & (0xF << s)) >> s;
}

extern "C" int func_00165EF8(void* self, unsigned char* src, unsigned char* dst)
{
    int n = 0;
    for (unsigned int i = 0; i < 4; i++) {
        int k = (i & 1) * 128;
        for (unsigned int j = 0; j < 16; j++) {
            for (unsigned int m = 0; m < 4; m++) {
                unsigned char lo = Nibble_00165EF8(src, D_0034DEF0[k++]);
                unsigned char hi = Nibble_00165EF8(src, D_0034DEF0[k++]);
                dst[n] = lo | ((hi << 4) & ~0xF);
                n++;
            }
        }
        src += 64;
    }
    return 0;
}
