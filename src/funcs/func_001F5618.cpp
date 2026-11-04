extern "C" int func_0032A660(void* mpeg);
extern "C" int func_001F53D0(void* mpeg);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_001E46B8();
extern "C" void func_001E4BE8(const char* msg);
extern "C" int func_0032A608(void* mpeg, void* pic, int n);
extern "C" void func_0032A680(void* mpeg);
extern "C" void func_001F7410(char* dst, char* src, int a, int w, int h);
extern char D_00366348[];
extern char D_00366360[];

struct Ring_001F5618 {
    char* m0;
    char* m4;
    int m8;
    int mC;
    int m10;
};

struct Player_001F5618 {
    char pad[0x673700];
    Ring_001F5618 ring;
};

extern Player_001F5618* D_0038E320;
extern "C" void* func_001F5138(Ring_001F5618* r);
extern "C" void func_001F50C0(Ring_001F5618* r);

struct Mpeg_001F5618 {
    int m0;
    int m4;
    int m8;
};

int Decode_001F5618(Mpeg_001F5618* m)
{
    int ret = 1;
    while (!func_0032A660(m)) {
        if (func_001F53D0(m) == 1) {
            ret = -1;
            func_00103F28(D_00366348);
            break;
        }
        void* pic;
        while (!(pic = func_001F5138(&D_0038E320->ring))) {
            func_001E46B8();
        }
        if (func_0032A608(m, pic, 0x654) < 0) {
            func_001E4BE8(D_00366360);
        }
        if (!m->m8) {
            int w = m->m0;
            int h = m->m4;
            for (int i = 0; i < D_0038E320->ring.m10; i++) {
                func_001F7410(D_0038E320->ring.m4 + i * 0x4CE40 + 0x40, D_0038E320->ring.m0 + i * (0x195 << 12), 0, w, h);
                func_001F7410(D_0038E320->ring.m4 + i * 0x4CE40 + 0x26740, D_0038E320->ring.m0 + i * (0x195 << 12), 1, w, h);
            }
        }
        func_001F50C0(&D_0038E320->ring);
        func_001E46B8();
    }
    func_0032A680(m);
    return ret;
}
