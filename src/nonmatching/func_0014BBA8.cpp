/* fuzzy: 93.6 */
/* sym: __12Img_0014BBA8i = 0x00146C90 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Res_0014BBA8 {
    char pad0[0x10];
    int m10;
};

class ImgBase_0014BBA8 {
public:
    int m0;
    int m4;
    virtual ~ImgBase_0014BBA8();
};

class Img_0014BBA8 : public ImgBase_0014BBA8 {
public:
    Img_0014BBA8(int a);
    virtual ~Img_0014BBA8();
    char pad0C[0x1C - 0xC];
    Res_0014BBA8* m1C;
    char pad20[0x2C - 0x20];
    Res_0014BBA8* m2C;
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

extern Img_0014BBA8* D_00393F18;
extern int D_0038882C;
extern int D_0038880C;
extern int D_00388814;
extern char D_0035F450[];
extern char D_0035F468[];
extern char D_0035F480[];
extern char D_0035F498[];
extern char D_0035F4B0[];
extern char D_0035F4C0[];

extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_003331D0(char* d, const char* fmt, ...);
extern "C" int func_00110DC8(const char* name);
extern "C" void func_00138618(Img_0014BBA8* img, const char* name, int a, int b);
extern "C" unsigned int func_00138948(Img_0014BBA8* img);
extern "C" int func_00138920(Img_0014BBA8* img);
extern "C" void func_0031BF20(int a);
extern "C" void func_003312D8(int a, int b);
extern "C" void func_003451F8(char* buf, short y, int a, int b, int c, short x, short h, short w);
extern "C" void func_003453E0(char* buf, int data);
extern "C" void func_001742A8();
extern "C" void func_00174208();
extern "C" void func_00177A50(int a);

static inline bool IsOne() { return D_0038882C == 1; }

extern "C" void func_0014BBA8(const char* name, int skip, int other)
{
    if (skip == 0 && other == 0) {
        D_00393F18 = new Img_0014BBA8(1);
        char buf[0x90];
        char path[0xA0];
        if (IsOne()) {
            func_00331A9C(buf, name);
        } else {
            switch (D_0038880C) {
            case 3: func_003331D0(buf, D_0035F450, name); break;
            case 4: func_003331D0(buf, D_0035F468, name); break;
            case 5: func_003331D0(buf, D_0035F480, name); break;
            case 6: func_003331D0(buf, D_0035F498, name); break;
            default: func_003331D0(buf, D_0035F4B0, name); break;
            }
            func_003331D0(path, D_0035F4C0, buf);
            if (!func_00110DC8(path)) {
                func_003331D0(buf, D_0035F4B0, name);
            }
        }
        func_00138618(D_00393F18, buf, 1, 1);
        Res_0014BBA8* res = D_00393F18->m2C;
        if (res == 0) res = D_00393F18->m1C;
        func_0031BF20(0);
        func_003312D8(0, 0);
        int h = (D_00388814 == 4) ? 0x265 : (D_0038882C == 0 ? 0x200 : 0x280);
        int y;
        int x = 0;
        if (D_00388814 != 4) {
            if (D_0038882C == 0) y = h * 8;
            else y = h * 7;
        } else {
            y = h * 0x740 / 256;
        }
        unsigned short half = func_00138948(D_00393F18) >> 1;
        int step = func_00138920(D_00393F18) * half * 2;
        int dx = half << 16;
        short sy = y;
        int off = 0;
        for (int i = 1; i >= 0; i--) {
            int a = (D_00388814 == 4) ? 9 : (D_0038882C == 0 ? 8 : 10);
            int cx = x >> 16;
            x += dx;
            func_003451F8(path, sy, a, 10, 0, cx, func_00138920(D_00393F18), half);
            func_0031BF20(0);
            func_003453E0(path, res->m10 + off);
            off += step;
            func_003312D8(0, 0);
        }
        delete D_00393F18;
        D_00393F18 = 0;
    }
    if (other) {
        func_001742A8();
        func_00174208();
    }
    func_00177A50(0);
}
