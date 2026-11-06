extern int D_0034E2F0[];

struct Obj_00166008 {
    int Fn(unsigned char* src, unsigned char* dst);
};

int Obj_00166008::Fn(unsigned char* src, unsigned char* dst)
{
    int n = 0;
    for (unsigned int i = 0; i < 4; i++) {
        int idx = (i & 1) << 6;
        for (unsigned int j = 0; j < 16; j++) {
            for (unsigned int k = 0; k < 4; k++) {
                dst[n] = src[D_0034E2F0[idx]];
                idx++;
                n++;
            }
        }
        src += 0x40;
    }
    return 0;
}
