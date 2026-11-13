/* fuzzy: 92.2 */
struct Heap_00148990 {
    char pad[0xD8];
    void* mD8;
};

extern Heap_00148990* D_00388A70;
extern "C" void func_0010A950(Heap_00148990* heap, void* sub);
extern "C" void* func_0010A638(Heap_00148990* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_00148990* heap);
extern "C" void func_0010A8D8(Heap_00148990* heap, void* p);
extern "C" void func_001483D8(void* img, void* buf, int x, int y, int w, int h);
extern "C" void func_00148518(void* img, void* buf, int x, int y, int w, int h);
extern "C" void func_00147860(void* src, int x, int y, int w, int h, void* dst, int dw, int dh, int bpp);
extern "C" void func_00147968(void* dst, int x, int y, int w, int h, void* src, int sw, int sh, int bpp);
extern "C" void func_00147A70(void* src, int sw, int sh, void* dst, int dw, int dh, int bpp);
extern "C" void func_00147DE8(void* a, void* b, int w, int h, int w2, int vertical, int bpp, float t);

extern "C" int func_00148990(void* img, unsigned short x, unsigned short y, unsigned short w, unsigned short h,
                             int vertical, unsigned short from, unsigned short to)
{
    unsigned short pos[2][2];
    unsigned short dst[2];
    unsigned short w1[2];
    unsigned short h1[2];
    unsigned short w2[2];
    unsigned short h2[2];
    void* part[2];
    void* scaled[2];
    float t;

    func_0010A950(D_00388A70, D_00388A70->mD8);
    void* buf = func_0010A638(D_00388A70, w * h * 4, 1, 0);
    func_0010A9B0(D_00388A70);
    func_001483D8(img, buf, x, y, w, h);
    pos[0][0] = 0;
    pos[0][1] = 0;
    if (!vertical) {
        int b = to - x;
        int a = from - x;
        w2[0] = b + 1;
        w1[0] = a + 1;
        w1[1] = w - a;
        w2[1] = w - b;
        h1[0] = h;
        h2[0] = h;
        t = (float)w2[0] / (float)w;
        pos[1][0] = a;
        pos[1][1] = 0;
        dst[0] = b;
        dst[1] = 0;
        h1[1] = h;
        h2[1] = h;
    } else {
        int b = to - y;
        int a = from - y;
        h2[0] = b + 1;
        h1[0] = a + 1;
        h1[1] = h - a;
        h2[1] = h - b;
        w1[0] = w;
        w2[0] = w;
        t = (float)h2[0] / (float)h;
        pos[1][0] = 0;
        pos[1][1] = a;
        dst[0] = 0;
        dst[1] = b;
        w1[1] = w;
        w2[1] = w;
    }
    func_0010A950(D_00388A70, D_00388A70->mD8);
    part[0] = func_0010A638(D_00388A70, w1[0] * h1[0] * 4, 1, 0);
    part[1] = func_0010A638(D_00388A70, w1[1] * h1[1] * 4, 1, 0);
    scaled[0] = func_0010A638(D_00388A70, w2[0] * h2[0] * 4, 1, 0);
    scaled[1] = func_0010A638(D_00388A70, w2[1] * h2[1] * 4, 1, 0);
    func_0010A9B0(D_00388A70);
    func_00147860(buf, pos[0][0], pos[0][1], w, h, part[0], w1[0], h1[0], 0x20);
    func_00147860(buf, pos[1][0], pos[1][1], w, h, part[1], w1[1], h1[1], 0x20);
    func_00147A70(part[0], w1[0], h1[0], scaled[0], w2[0], h2[0], 0x20);
    func_00147A70(part[1], w1[1], h1[1], scaled[1], w2[1], h2[1], 0x20);
    func_00147DE8(scaled[0], scaled[1], w2[0], h2[0], w2[1], vertical, 0x20, t);
    func_00147968(buf, pos[0][0], pos[0][1], w, h, scaled[0], w2[0], h2[0], 0x20);
    func_00147968(buf, dst[0], dst[1], w, h, scaled[1], w2[1], h2[1], 0x20);
    func_00148518(img, buf, x, y, w, h);
    if (part[0])
        func_0010A8D8(D_00388A70, part[0]);
    if (part[1])
        func_0010A8D8(D_00388A70, part[1]);
    if (scaled[0])
        func_0010A8D8(D_00388A70, scaled[0]);
    if (scaled[1])
        func_0010A8D8(D_00388A70, scaled[1]);
    if (buf)
        func_0010A8D8(D_00388A70, buf);
    return 1;
}
