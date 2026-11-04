extern unsigned char* D_003942CC;
extern char D_00361580[];
extern char D_00361598[];
extern "C" void func_0031BF20(int a);
extern "C" void func_003312D8(int a, int b);
extern "C" void func_00165058();
extern "C" void func_00181E38(unsigned char* dst, int a, int b, int c, short y, int w, short h, int stride);
extern "C" void func_00181D70(unsigned char* hdr, int w, int h);
extern "C" int func_001E5648(const char* name, int a);
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00182230(const char* name, unsigned char* data);

extern "C" void func_001822F0(int unused, const char* name)
{
    int y = 0;
    int band = 32;
    int height = 448;
    int pitch = 640 * 3;
    func_0031BF20(0);
    func_003312D8(0, 0);
    func_00165058();
    func_003312D8(0, 0);
    unsigned char* image = D_003942CC + 0x40;
    for (; y < height / band; y++) {
        unsigned char* src = image + y * pitch * band;
        func_00181E38(src, 0, 0, 0, y * band, 640, band, 640);
        unsigned char* dst = src;
        for (int i = 0; i < 640 * band; i++) {
            unsigned char b = src[2];
            unsigned char g = src[1];
            unsigned char r = src[0];
            *dst++ = b;
            *dst++ = g;
            *dst++ = r;
            src += 4;
        }
    }
    unsigned char* top = image;
    unsigned char* bottom = image + 447 * 0x780;
    for (int row = 0; row < 224; row++) {
        for (int x = 0; x < 0x780; x++) {
            unsigned char a = bottom[x];
            unsigned char b = top[x];
            top[x] = a;
            bottom[x] = b;
        }
        top += 0x780;
        bottom -= 0x780;
    }
    func_00181D70(D_003942CC + 0xA, 640, 448);
    unsigned char* in = D_003942CC + 0xA;
    unsigned char* out = D_003942CC;
    for (int n = 0; n < 640 * 448 * 3 + 0x36; n++) {
        *out++ = *in++;
    }
    image = D_003942CC;
    if (func_001E5648(D_00361580, 1)) {
        func_00103F28(D_00361598);
    } else {
        func_00182230(name, image);
    }
    func_0031BF20(0);
}
