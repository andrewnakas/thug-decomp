/* fuzzy: 88.0 */
/* blocked: global-alloc priority differences (116 vs 232, 128 vs 177; forced 67 -> 1 word) (oracle) */
struct Heap_00148FE0 {
    char pad[0xD8];
    int mD8;
};

struct Img_00148FE0 {
    char pad[0xC];
    unsigned short w;
    unsigned short h;
};

extern Heap_00148FE0* D_00388A70;
extern "C" void func_0010A950(Heap_00148FE0* heap, int sub);
extern "C" void* func_0010A638(Heap_00148FE0* heap, int size, int a, int b);
extern "C" void func_0010A9B0(Heap_00148FE0* heap);
extern "C" void func_0010A8D8(Heap_00148FE0* heap, void* p);
extern "C" void func_001483D8(Img_00148FE0* img, unsigned int* buf, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
extern "C" void func_00148518(Img_00148FE0* img, unsigned int* buf, unsigned short x, unsigned short y, unsigned short w, unsigned short h);
extern "C" void func_00147A70(unsigned int* src, unsigned short sw, unsigned short sh, unsigned int* dst, unsigned short dw, unsigned short dh, int bpp);
extern "C" void func_00147968(unsigned int* dst, unsigned short x, unsigned short y, unsigned short dw, unsigned short dh, unsigned int* src, unsigned short sw, unsigned short sh, int bpp);
extern "C" void* func_00331404(void* d, const void* s, int n);

extern "C" int func_00148FE0(Img_00148FE0* img, unsigned short pos, int axis, int amount, int fill, unsigned int* color)
{
    if (amount == 0) return 1;
    unsigned short src[2];
    unsigned short dst[2];
    unsigned short sw, sh, dw, dh;
    if (pos + amount <= 0) {
        amount = -pos + 1;
    }
    if (axis == 0) {
        if (pos + amount >= img->w) {
            amount = img->w - pos - 1;
        }
        if (amount < 0) {
            src[0] = pos;
            src[1] = 0;
            int d = img->w - pos;
            sw = d;
            sh = img->h;
            dw = d + amount;
            dst[0] = 0;
        } else {
            src[0] = 0;
            src[1] = 0;
            sw = pos + 1;
            sh = img->h;
            dw = pos - amount + 1;
            dst[0] = amount;
        }
        dst[1] = 0;
        dh = img->h;
    } else {
        if (pos + amount >= img->h) {
            amount = img->h - pos - 1;
        }
        if (amount < 0) {
            src[0] = 0;
            src[1] = pos;
            int d = img->h - pos;
            sh = d;
            sw = img->w;
            dh = d + amount;
            dst[0] = 0;
            dst[1] = 0;
        } else {
            src[0] = 0;
            src[1] = 0;
            sh = pos + 1;
            sw = img->w;
            dh = pos - amount + 1;
            dst[0] = 0;
            dst[1] = amount;
        }
        dw = img->w;
    }
    func_0010A950(D_00388A70, D_00388A70->mD8);
    unsigned int* sbuf = (unsigned int*)func_0010A638(D_00388A70, sw * sh * 4, 1, 0);
    unsigned int* dbuf = (unsigned int*)func_0010A638(D_00388A70, dw * dh * 4, 1, 0);
    func_0010A9B0(D_00388A70);
    func_001483D8(img, sbuf, src[0], src[1], sw, sh);
    func_00147A70(sbuf, sw, sh, dbuf, dw, dh, 0x20);
    if (fill) {
        unsigned int* p = sbuf;
        for (int i = 0; i < sw * sh; i++) {
            *p++ = *color;
        }
    }
    func_00147968(sbuf, dst[0], dst[1], sw, sh, dbuf, dw, dh, 0x20);
    func_00148518(img, sbuf, src[0], src[1], sw, sh);
    if (!fill) {
        if (axis == 0) {
            bool pos2 = amount > 0;
            int cx = dw - 1;
            if (pos2) cx = 0;
            func_0010A950(D_00388A70, D_00388A70->mD8);
            unsigned int* col = (unsigned int*)func_0010A638(D_00388A70, img->h * 4, 1, 0);
            func_0010A9B0(D_00388A70);
            for (int y = 0; y < img->h; y++) {
                col[y] = dbuf[cx + y * dw];
            }
            int x0 = pos2 ? 0 : img->w + amount;
            int x1 = pos2 ? amount - 1 : img->w - 1;
            for (int x = x0; x <= x1; x++) {
                func_00148518(img, col, x, 0, 1, img->h);
            }
            if (col) func_0010A8D8(D_00388A70, col);
        } else {
            int cy = dh - 1;
            bool pos2 = amount > 0;
            if (pos2) cy = 0;
            func_0010A950(D_00388A70, D_00388A70->mD8);
            unsigned int* row = (unsigned int*)func_0010A638(D_00388A70, img->w * 4, 1, 0);
            func_0010A9B0(D_00388A70);
            unsigned int* p = dbuf;
            p += cy * dw;
            func_00331404(row, p, img->w * 4);
            int y0 = pos2 ? 0 : img->h + amount;
            int y1 = pos2 ? amount - 1 : img->h - 1;
            for (int y = y0; y <= y1; y++) {
                func_00148518(img, row, 0, y, img->w, 1);
            }
            if (row) func_0010A8D8(D_00388A70, row);
        }
    }
    if (sbuf) func_0010A8D8(D_00388A70, sbuf);
    if (dbuf) func_0010A8D8(D_00388A70, dbuf);
    return 1;
}
