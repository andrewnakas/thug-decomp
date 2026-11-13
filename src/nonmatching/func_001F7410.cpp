/* fuzzy: 89.6 */
typedef int qword __attribute__((mode(TI)));

struct Pk_001F7410 {
    unsigned int* m_cur;
    unsigned int* m_base;
    int m8;
    unsigned int* m_tag;
};

struct Tag_001F7410 {
    unsigned long lo;
    unsigned long hi;
};

union TagQ_001F7410 {
    Tag_001F7410 t;
    qword q;
};

extern Tag_001F7410 D_00366458;
extern Tag_001F7410 D_00366448;
extern int D_0038882C;
extern "C" void func_00322EE0(Pk_001F7410* pk, void* buf);
extern "C" void func_00322EF0(Pk_001F7410* pk);
extern "C" void func_00322F58(Pk_001F7410* pk, int a, int b, int c);
extern "C" void func_003230F8(Pk_001F7410* pk, qword tag);
extern "C" void func_003231B8(Pk_001F7410* pk, unsigned int reg, unsigned long data);
extern "C" void func_00323110(Pk_001F7410* pk);
extern "C" unsigned long* func_003230E0(Pk_001F7410* pk, int n);
extern "C" void func_00322FD0(Pk_001F7410* pk, void* addr, int qwc, int a, int b, int c);
extern "C" void func_00323068(Pk_001F7410* pk, int a, int b, int c);
extern "C" void func_00322F00(Pk_001F7410* pk);

extern "C" void func_001F7410(unsigned int buf, unsigned int src, int noUpload, int w, int h)
{
    int uv[4];
    int xy[4];
    Pk_001F7410 pk;
    TagQ_001F7410 tagImage;
    TagQ_001F7410 tagSprite;
    tagImage.t = D_00366458;
    tagSprite.t = D_00366448;
    int bw = w >> 4;
    int bh = h >> 4;
    func_00322EE0(&pk, (void*)((buf & 0x0FFFFFFF) | 0x20000000));
    func_00322EF0(&pk);
    if (!noUpload) {
        func_00322F58(&pk, 0, 0, 0);
        func_003230F8(&pk, tagImage.q);
        func_003231B8(&pk, 0x50, (unsigned long)0xC1B0 << 36);
        func_003231B8(&pk, 0x52, ((unsigned long)0x10 << 32) | 0x10);
        func_00323110(&pk);
        for (int i = 0; i < bw; i++) {
            /* TRXDIR data: the game zero-extends a 32-bit 0 (dsll32 s4 in the preheader, dsrl32 a2,s4 per call) */
            unsigned int dir = 0;
            for (int j = 0, y = 0; j < bh; j++, y += 16) {
                unsigned int x = i * 16;
                func_00322F58(&pk, 0, 0, 0);
                func_003230F8(&pk, tagImage.q);
                func_003231B8(&pk, 0x51, ((unsigned long)x << 32) | ((unsigned long)y << 48));
                func_003231B8(&pk, 0x53, dir);
                func_00323110(&pk);
                unsigned long* p = func_003230E0(&pk, 4);
                p[0] = ((unsigned long)0x08000000 << 32) | 0x40;
                p[1] = 0;
                func_00322FD0(&pk, (void*)(src & 0x0FFFFFFF), 0x40, 0, 0, 0);
                src += 0x400;
            }
        }
    }
    uv[2] = w << 4;
    uv[3] = h << 4;
    uv[0] = 8;
    uv[1] = 8;
    if (!D_0038882C) {
        xy[0] = 0x6C00;
        xy[1] = 0x7800;
        xy[2] = 0x2800;
        xy[3] = 0x1000;
    } else {
        xy[0] = 0x6C00;
        xy[1] = 0x7880;
        xy[2] = 0x2800;
        xy[3] = 0xF00;
    }
    func_00323068(&pk, 0, 0, 0);
    func_003230F8(&pk, tagSprite.q);
    func_003231B8(&pk, 0x3F, 0);
    func_003231B8(&pk, 0x14, 0x60);
    func_003231B8(&pk, 0x06, 0xAA8031B00);
    func_003231B8(&pk, 0x00, 0x116);
    func_003231B8(&pk, 0x03, uv[0] | ((unsigned long)uv[1] << 16));
    func_003231B8(&pk, 0x05, xy[0] | ((unsigned long)xy[1] << 16));
    func_003231B8(&pk, 0x03, (uv[0] + uv[2]) | ((unsigned long)(uv[1] + uv[3]) << 16));
    func_003231B8(&pk, 0x05, (xy[0] + xy[2]) | ((unsigned long)(xy[1] + xy[3]) << 16));
    func_00323110(&pk);
    func_00322F00(&pk);
}
