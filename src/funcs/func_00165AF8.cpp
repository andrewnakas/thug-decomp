extern int D_0034D6F0[32];
extern int D_0034D770[32];
extern int D_0034D7F0[32];
extern unsigned int* D_00393F38;

extern "C" void func_00165AF8(int bp, int bw, int x0, int y0, int w, int h, unsigned short* dst)
{
    bp *= 64;
    for (int y = y0; y < y0 + h; y++) {
        int py = y / 64;
        int ry = y % 64;
        int by = ry / 8;
        int ry8 = ry % 8;
        int cy = ry8 / 2;
        int cyr = ry8 % 2;
        for (int x = x0; x < x0 + w; x++) {
            int px = x / 64;
            int rx = x % 64;
            int bx = rx / 16;
            int cx = rx % 16;
            int bi = bx + by * 4;
            int ci = cx + cyr * 16;
            unsigned int* page = D_00393F38 + (bp + (px + py * bw) * 2048 + D_0034D6F0[bi] * 64 + cy * 16
                                               + D_0034D770[ci]);
            *dst++ = ((unsigned short*)page)[D_0034D7F0[ci]];
        }
    }
}
