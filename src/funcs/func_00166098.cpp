struct Row16_00166098 { unsigned char b[16]; };
struct Row32_00166098 { unsigned char b[32]; };

extern int D_0034E570[];
extern int D_0034E4F0[];

extern "C" void* func_003341E0(int size);
extern "C" void func_00334230(void* p);
extern "C" void* func_003315B8(void* p, int c, int n);
extern "C" int func_00165EF8(void* ctx, unsigned char* in, unsigned char* out); // game: callee sets v0=0

extern "C" int func_00166098(void* ctx, int width, int height, unsigned char* src, unsigned char* dst)
{
    unsigned char block[0x100];
    unsigned char out[0x100];
    int* col = (int*)func_003341E0(0x80);
    int* row = (int*)func_003341E0(0x80);
    int k = 0;
    int i, j;
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 8; i++) {
            int idx = D_0034E570[k++];
            col[idx] = i;
            row[idx] = j;
        }
    }
    int mbw = width / 32;
    int mbh = height / 16;
    func_003315B8(block, 0, 0x100);
    func_003315B8(out, 0, 0x100);
    for (j = 0; j < mbh; j++) {
        int srcPitch = 0x40;
        int dstPitch = 0x100;
        for (i = 0; i < mbw; i++) {
            int n = D_0034E4F0[j * mbw + i];
            Row16_00166098* s = (Row16_00166098*)(src + j * 16 * srcPitch + i * 16);
            Row16_00166098* d = (Row16_00166098*)block;
            int r;
            for (r = 0; r < 16; r++) {
                *d = *s;
                d++;
                s = (Row16_00166098*)((unsigned char*)s + srcPitch);
            }
            func_00165EF8(ctx, block, out);
            Row32_00166098* s2 = (Row32_00166098*)out;
            Row32_00166098* d2 = (Row32_00166098*)(dst + row[n] * 8 * dstPitch + col[n] * 32);
            for (r = 0; r < 8; r++) {
                *d2 = *s2;
                s2++;
                d2 = (Row32_00166098*)((unsigned char*)d2 + dstPitch);
            }
        }
    }
    func_00334230(col);
    func_00334230(row);
    return 0;
}
