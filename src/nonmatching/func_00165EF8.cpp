/* fuzzy: 63.4 */
/* blocked: global-alloc priority (dst 118 p1923 vs PRE reg 184 p1860) and inner-loop sched1 priority/hazard order; forced 36 -> 27 words (oracle) */
extern unsigned int D_0034DEF0[256];

static inline unsigned char Nibble_00165EF8(unsigned char* src, unsigned int a)
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
