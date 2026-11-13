/* fuzzy: 72.6 */
struct Row16_00166098 {
    unsigned char b[16];
};

struct Row32_00166098 {
    unsigned char b[32];
};

extern int D_0034E570[];
extern int D_0034E4F0[];

extern "C" void* func_003341E0(int size);
extern "C" void func_00334230(void* p);
extern "C" void* func_003315B8(void* p, int c, int n);
static inline void* Wrap_003315B8(void* p, int c, int n) { return func_003315B8(p, c, n); }
extern "C" void func_00165EF8(void* ctx, void* in, void* out);

static inline void ReadBlock(Row16_00166098* in, unsigned char* src, int pitch, int bx, int by)
{
    unsigned char* s = src + by * 16 * pitch + bx * 16;
    for (int r = 0; r < 16; r++) {
        in[r] = *(Row16_00166098*)(s + r * pitch);
    }
}

static inline void WriteBlock(unsigned char* dst, int pitch, int bx, int by, Row32_00166098* out)
{
    unsigned char* d = dst + by * 8 * pitch + bx * 32;
    for (int r = 0; r < 8; r++) {
        *(Row32_00166098*)(d + r * pitch) = out[r];
    }
}

extern "C" int func_00166098(void* ctx, int w, int h, unsigned char* src, unsigned char* dst)
{
    int* col = (int*)func_003341E0(0x80);
    int* row = (int*)func_003341E0(0x80);
    int n = 0;
    for (int k = 0; k < 4; k++) {
        for (int j = 0; j < 8; j++) {
            int idx = D_0034E570[n++];
            col[idx] = j;
            row[idx] = k;
        }
    }
    int spitch = 0x40;
    int dpitch = 0x100;
    int bw = w / 32;
    int bh = h / 16;
    Row16_00166098 in[16];
    Row32_00166098 out[8];
    Wrap_003315B8(in, 0, 0x100);
    Wrap_003315B8(out, 0, 0x100);
    for (int y = 0; y < bh; y++) {
        for (int x = 0; x < bw; x++) {
            int b = D_0034E4F0[y * bw + x];
            unsigned char* sp = src + y * 16 * spitch + x * 16;
            for (int r = 0; r < 16; r++) {
                in[r] = *(Row16_00166098*)(sp + r * spitch);
            }
            func_00165EF8(ctx, in, out);
            unsigned char* dp = dst + row[b] * 8 * dpitch + col[b] * 32;
            for (int r = 0; r < 8; r++) {
                *(Row32_00166098*)(dp + r * dpitch) = out[r];
            }
        }
    }
    func_00334230(col);
    func_00334230(row);
    return 0;
}
