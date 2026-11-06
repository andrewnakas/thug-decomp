/* fuzzy: 87.2 */
extern int D_0034D870[];
extern int D_0034D8F0[2][128];
extern int D_0034DCF0[];
extern unsigned char* D_00393F38;

extern "C" void func_00165CB0(int base, int bw, int x0, int y0, int w, int h, unsigned char* src)
{
    int b64 = base << 6;
    int nib = 0;
    int pages = bw >> 1;
    for (int y = y0; y < y0 + h; y++) {
        int py = y / 128;
        int ry = y % 128;
        int by = ry / 16;
        int r16 = ry % 16;
        int cy = r16 / 4;
        int r4 = r16 % 4;
        for (int x = x0; x < x0 + w; x++) {
            int px = x / 128;
            int rx = x % 128;
            int bx = rx / 32;
            int r32 = rx % 32;
            int page = px + py * pages;
            int sub = D_0034D8F0[cy & 1][r32 + r4 * 32];
            int n = D_0034DCF0[r32 + r4 * 32];
            int blk = D_0034D870[bx + by * 4];
            unsigned char* p = D_00393F38 + (b64 + (page << 11) + (blk << 6) + (cy << 4) + sub) * 4;
            if (n & 1) {
                if (nib) {
                    p[n >> 1] = (p[n >> 1] & 0xF) | (*src & 0xF0);
                } else {
                    p[n >> 1] = (p[n >> 1] & 0xF) | ((*src << 4) & 0xF0);
                }
            } else {
                if (nib) {
                    p[n >> 1] = (p[n >> 1] & 0xF0) | (*src >> 4);
                } else {
                    p[n >> 1] = (p[n >> 1] & 0xF0) | (*src & 0xF);
                }
            }
            if (nib) src++;
            nib ^= 1;
        }
    }
}
