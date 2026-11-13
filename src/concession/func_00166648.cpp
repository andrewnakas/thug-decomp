/* force: {"kind": "ga", "before": [124, 122]} */
/* force: {"kind": "ga", "before": [137, 135]} */
struct File_00166648 {
    char pad0[0xC];
    void* mC;
};

extern File_00166648* D_0035997C[];
extern char D_00360CC8[];

extern "C" int func_00332798(void* f, const char* fmt);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" void* func_00331404(void* dst, const void* src, unsigned int n);
extern "C" int func_00166098(void* ctx, int w, int h, unsigned char* in, unsigned char* out);
extern "C" int func_001665E8(void* ctx, int w, int h);

static inline int SizeLog_00166648(int s)
{
    int i;
    for (i = 0; i < 11; i++) {
        if (s == (0x400 >> i)) break;
    }
    return i;
}

int func_00166648(void* ctx, int width, int height, unsigned char* src, unsigned char* dst)
{
    unsigned char in[0x2000];
    unsigned char out[0x2000];

    if (SizeLog_00166648(width) == 11) {
        func_00332798(D_0035997C[0]->mC, D_00360CC8);
        return 0;
    }
    func_003315B8(in, 0, 0x2000);
    func_003315B8(out, 0, 0x2000);
    if (SizeLog_00166648(height) == 11) {
        func_00332798(D_0035997C[0]->mC, D_00360CC8);
        return 0;
    }

    int nx = (width - 1) / 128 + 1;
    int ny = (height - 1) / 128 + 1;
    int inRow;
    int inRows;
    int outRow;
    int outRows;
    if (nx == 1) {
        inRow = width / 2;
        outRows = width / 4;
    } else {
        inRow = 0x40;
        outRows = 0x20;
    }
    if (ny == 1) {
        inRows = height;
        outRow = height * 2;
    } else {
        outRow = 0x100;
        inRows = 0x80;
    }

    int y, x, r;
    for (y = 0; y < ny; y++) {
        for (x = 0; x < nx; x++) {
            unsigned char* s = src + inRow * (nx << 7) * y + inRow * x;
            unsigned char* d = in;
            for (r = 0; r < inRows; r++) {
                func_00331404(d, s, inRow);
                s += inRow * nx;
                d += 0x40;
            }
            func_00166098(ctx, 0x80, 0x80, in, out);
            unsigned char* d2 = dst + outRow * (nx << 5) * y + outRow * x;
            unsigned char* s2 = out;
            for (r = 0; r < outRows; r++) {
                func_00331404(d2, s2, outRow);
                d2 += outRow * nx;
                s2 += 0x100;
            }
        }
    }
    return func_001665E8(ctx, width, height);
}
