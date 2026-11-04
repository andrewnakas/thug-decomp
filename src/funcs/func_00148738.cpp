struct Heap_00148738 {
    char pad[0xD8];
    int mD8;
};

struct Img_00148738 {
    char pad[0xC];
    unsigned short w;
    unsigned short h;
};

extern Heap_00148738* D_00388A70;
extern "C" void func_0010A950(Heap_00148738* heap, int sub);
extern "C" void* func_0010A638(Heap_00148738* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_00148738* heap);
extern "C" void func_0010A8D8(Heap_00148738* heap, void* p);
extern "C" void func_001483D8(Img_00148738* img, unsigned int* buf, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
extern "C" void func_00148518(Img_00148738* img, unsigned int* buf, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
extern "C" void func_00148678(Img_00148738* img, unsigned int c, unsigned short x, unsigned short y);

static inline int Clamp(int v, int lo, int hi)
{
    if (v < lo) v = lo;
    if (v > hi) v = hi;
    return v;
}

extern "C" int func_00148738(Img_00148738* img, int dx, int dy, int wrap)
{
    int src[2];
    int dst[2];
    int w, h;
    if (dx >= 0) {
        src[0] = 0;
        dst[0] = dx;
        w = img->w - dx;
    } else {
        src[0] = -dx;
        dst[0] = 0;
        w = img->w - src[0];
    }
    if (dy >= 0) {
        src[1] = 0;
        dst[1] = dy;
        h = img->h - dy;
    } else {
        src[1] = -dy;
        dst[1] = 0;
        h = img->h - src[1];
    }
    func_0010A950(D_00388A70, D_00388A70->mD8);
    unsigned int* buf = (unsigned int*)func_0010A638(D_00388A70, w * h * 4, 1, 0);
    func_0010A9B0(D_00388A70);
    func_001483D8(img, buf, src[0], src[1], w, h);
    func_00148518(img, buf, dst[0], dst[1], w, h);
    if (!wrap) {
        int py = -dst[1];
        for (int y = 0; y < img->h; y++, py++) {
            int row = Clamp(py, 0, h - 1) * w;
            int px = -dst[0];
            for (int x = 0; x < img->w; x++, px++) {
                if (px < 0 || px >= w || py < 0 || py >= h) {
                    int cx = px;
                    if (cx < 0) cx = 0;
                    if (cx > w - 1) cx = w - 1;
                    func_00148678(img, buf[row + cx], x, y);
                }
            }
        }
    }
    if (buf) {
        func_0010A8D8(D_00388A70, buf);
    }
    return 1;
}
