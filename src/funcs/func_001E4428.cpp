extern char* D_0038E320;
extern int D_0038E318;
extern int D_0038E31C;
extern int D_0039411C;
extern long D_00394120;
extern "C" int func_0031A468(int, int, unsigned char*);
extern "C" void func_001F53C0(void*);
extern "C" long func_0010FA80();
extern "C" int func_001F6D98(void*, int*);
extern "C" int func_001F6D38(void*, int, int);
extern "C" void func_001F6DC8(void*, int);
extern "C" void func_001E46B8();
extern "C" int func_001F6E10(void*, int*);
extern "C" int func_003297C0(void*, int, int, void*, int);
extern "C" void func_001F6E58(void*, int);
extern "C" void func_001E4C10();
extern "C" int func_001F50A8(void*);
extern "C" int func_001E46D8();
extern "C" void func_001F79B0(int);
extern "C" void func_001F7C80(void*);
extern "C" void func_001F7CA0(void*);
extern "C" int func_001F53D0(void*);
extern "C" int func_001F5458(void*);
extern "C" int func_001F5530(void*);
extern "C" void func_001F79F0();

struct Player_001E4428 {
    int m0;
    int m4;
    int m8;
};

struct Info_001E4428 {
    int m0;
    int m4;
};

struct Dec_001E4428 {
    char pad[0x50008];
    int m50008;
};

int func_001E4428(Player_001E4428* pl, Dec_001E4428* dec, Info_001E4428* info)
{
    unsigned char pad[32];
    int a;
    int b;
    int started = 0;
    int prev = 0;
    int left = info->m4;
    int remain = left;

    while (left >= 5 && func_001F53D0(pl) != 3) {
        if (func_0031A468(0, 0, pad) > 0)
            D_0039411C = ((pad[2] << 8) | pad[3]) ^ 0xFFFF;
        else
            D_0039411C = 0;
        int cur = D_0039411C;
        int pressed = (prev ^ cur) & cur;
        prev = cur;
        if (pressed & 0x840) {
            if (pl->m8 >= 11) {
                func_001F53C0(D_0038E320 + 0x6735C0);
                if (pressed & 0x800) {
                    D_00394120 = func_0010FA80();
                    D_0038E31C = 1;
                } else {
                    D_0038E31C = 0;
                }
            }
        }
        int n = func_001F6D98(dec, &a);
        if (remain > 0 && n > 0xFFFF) {
            int k = func_001F6D38(info, a, 0x10000);
            remain -= k;
            func_001F6DC8(dec, k);
        }
        func_001E46B8();
        int m = func_001F6E10(dec, &b);
        if (m > 0) {
            int k = func_003297C0(pl, b, m, dec, dec->m50008);
            left -= k;
            func_001F6E58(dec, k);
        }
        func_001E4C10();
        if (!started && func_001F50A8(D_0038E320 + 0x673700) && func_001E46D8()) {
            func_001F79B0(1);
            if (D_0038E318)
                func_001F7C80(D_0038E320 + 0x673680);
            started = 1;
        }
    }
    while (!func_001F5458(pl))
        func_001E46B8();
    while (!func_001F5530(pl) && func_001F53D0(pl) != 3)
        func_001E46B8();
    func_001F79F0();
    if (D_0038E318)
        func_001F7CA0(D_0038E320 + 0x673680);
    return 1;
}
