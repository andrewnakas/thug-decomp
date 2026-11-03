struct Heap_00147FB0 {
    char pad[0xD8];
    void* mD8;
};

struct Img_00147FB0 {
    char pad[0x14];
    unsigned char* m_palette;
};

struct Tex_00147FB0 {
    char pad[0x10];
    unsigned char m_depth;
    char pad11[0xB];
    Img_00147FB0* m_img;
};

struct Cell_00147FB0 {
    short m_start;
    unsigned char m_count;
    unsigned char m_pad;
};

extern Heap_00147FB0* D_00388A70;
extern int D_00393F14;
extern unsigned char* D_0038A8C4;
extern Cell_00147FB0 D_003C7DC8[8][8][8][8];
extern "C" void func_0010A950(Heap_00147FB0* heap, void* sub);
extern "C" void* func_0010A638(Heap_00147FB0* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_00147FB0* heap);

extern "C" void func_00147FB0(Tex_00147FB0* tex, int alpha)
{
    int lo[4];
    int hi[4];
    D_00393F14 = alpha;
    int na = alpha ? 8 : 1;
    int n = 1 << tex->m_depth;
    int step = n >> 3;
    int size = na * ((n / 2) << 9);
    func_0010A950(D_00388A70, D_00388A70->mD8);
    D_0038A8C4 = (unsigned char*)func_0010A638(D_00388A70, size, 1, 0);
    func_0010A9B0(D_00388A70);
    int half = n >> 4;
    int top = step + half;
    int bottom = -half;
    int atop = D_00393F14 ? top : n;
    int count = 0;
    lo[0] = bottom;
    hi[0] = top;
    for (int r = 0; r < 8; r++) {
        lo[1] = bottom;
        hi[1] = top;
        for (int g = 0; g < 8; g++) {
            lo[2] = bottom;
            hi[2] = top;
            for (int b = 0; b < 8; b++) {
                lo[3] = bottom;
                hi[3] = atop;
                for (int a = 0; a < na; a++) {
                    Cell_00147FB0* c = &D_003C7DC8[r][g][b][a];
                    c->m_start = count;
                    c->m_count = 0;
                    unsigned char* p = tex->m_img->m_palette;
                    for (int i = 0; i < n; i++, p += 4) {
                        if (p[0] < lo[0] || p[0] > hi[0])
                            continue;
                        if (p[1] < lo[1] || p[1] > hi[1])
                            continue;
                        if (p[2] < lo[2] || p[2] > hi[2])
                            continue;
                        if (p[3] < lo[3] || p[3] > hi[3])
                            continue;
                        c->m_count++;
                        D_0038A8C4[count] = i;
                        count++;
                    }
                    lo[3] += step;
                    hi[3] += step;
                }
                lo[2] += step;
                hi[2] += step;
            }
            lo[1] += step;
            hi[1] += step;
        }
        lo[0] += step;
        hi[0] += step;
    }
}
