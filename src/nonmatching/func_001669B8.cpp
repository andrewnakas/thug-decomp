/* fuzzy: 90.6 */
struct File_001669B8 {
    char pad0[0xC];
    void* mC;
};

extern File_001669B8* D_0035997C[];
extern char D_00360CC8[];   /* "Error : width is not 2^n\n" */
extern "C" int func_00332798(void* f, const char* fmt);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" void* func_00331404(void* dst, const void* src, int n);
extern "C" int func_00166340(void* ctx, int width, int height, unsigned char* src, unsigned char* dst);
extern "C" int func_00166CB8(void* ctx, int width, int height);

static inline int Log2_001669B8(int v)
{
    int i;
    for (i = 0; i < 11 && v != (0x400 >> i); i++)
        ;
    return i;
}

/* swizzles a width x height texture block by block (128x64 source blocks) through func_00166340 */
extern "C" int func_001669B8(void* ctx, int width, int height, unsigned char* src, unsigned char* dst)
{
    unsigned char in[0x2000];
    unsigned char out[0x2000];

    if (Log2_001669B8(width) == 11 || Log2_001669B8(height) == 11) {
        func_00332798(D_0035997C[0]->mC, D_00360CC8);
        return 0;
    }

    func_003315B8(in, 0, sizeof(in));
    func_003315B8(out, 0, sizeof(out));

    int nx = (width - 1) / 128 + 1;
    int ny = (height - 1) / 64 + 1;
    int bw, obw;
    if ((width - 1) / 128 == 0) {
        bw = width;
        obw = width * 2;
    } else {
        bw = 0x80;
        obw = 0x100;
    }
    int rows = 0x40;
    int orows = 0x20;
    if (ny == 1) {
        rows = height;
        orows = height / 2;
    }

    for (int by = 0; by < ny; by++) {
        for (int bx = 0; bx < nx; bx++) {
            unsigned char* p = src + bw * 64 * nx * by + bw * bx;
            unsigned char* q = in;
            for (int r = 0; r < rows; r++) {
                func_00331404(q, p, bw);
                p += bw * nx;
                q += 0x80;
            }
            func_00166340(ctx, 0x80, 0x40, in, out);
            unsigned char* p2 = dst + obw * orows * nx * by + obw * bx;
            unsigned char* q2 = out;
            for (int r = 0; r < orows; r++) {
                func_00331404(p2, q2, obw);
                p2 += obw * nx;
                q2 += 0x100;
            }
        }
    }
    return func_00166CB8(ctx, width, height);
}
