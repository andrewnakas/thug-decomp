extern char D_0035C240[];
extern char D_0035C290[];
extern char D_0035C2D8[];
extern char D_0035C310[];
extern char D_0035C330[];
extern char D_0035C340[];
extern char D_0035C350[];
extern char D_0035C360[];
extern char D_0035C370[];
extern char D_0035C380[];
extern char D_0035C390[];
extern char D_0035C3A0[];
extern char D_0035C3B0[];
extern char D_0035C3C0[];
extern char D_00388F50[];
extern char D_00388F58[];
extern char D_00388F60[];
extern char D_00388F68[];
extern char D_00388F70[];
extern char D_00388F78[];
extern char D_003BD8A8[];
extern int D_0038880C;
extern int D_00388810;
extern int D_00388814;
extern int D_00388818;
extern int D_0038881C;
extern int D_00388820;
extern int D_00388824;
extern int D_0038882C;
extern int D_00388830;
extern char* D_0038883C;

extern "C" int func_00103F28(const char* fmt, ...);
extern "C" int func_00331BB8(const char* s);
extern "C" int func_00336228(const char* a, const char* b);
extern "C" char* func_00332088(char* dst, const char* src, int n);
extern "C" int func_00346230(const char* s);
extern "C" bool func_001065E0(const char* name, int argc, char** argv);
extern "C" char* func_001064B8(const char* name, int argc, char** argv);
extern "C" char* func_00114160(const char* s);

void func_001141B8(int argc, char** argv)
{
    D_00388814 = 0;
    D_00388818 = 0;
    D_0038881C = 0;
    if (argc >= 2) {
        if ((unsigned int)((unsigned char)argv[1][0] - '0') < 10) {
            func_00103F28(D_0035C240, argv[1]);
            D_00388820 = 1;
            D_00388824 = 1;
            D_00388814 = 1;
            D_00388818 = 0;
            D_0038881C = 1;
            D_0038880C = 2;
            D_0038882C = 1;
            D_00388830 = 60;
            D_00388810 = 0;
            return;
        }
        func_00103F28(D_0035C290, argv[1]);
    } else {
        func_00103F28(D_0035C2D8);
    }
    if (func_00336228(argv[0] + func_00331BB8(argv[0]) - 4, D_00388F50) == 0) {
        char* p = argv[0] + func_00331BB8(argv[0]) - 5;
        while (*p != '\\') p--;
        p++;
        char* d = D_003BD8A8;
        while (*p != '.') *d++ = *p++;
        *d = 0;
    }
    if (!argv[0] || func_00336228(argv[0] + func_00331BB8(argv[0]) - 4, D_00388F50) == 0) {
        D_00388814 = 3;
        D_00388818 = 1;
        D_0038881C = 0;
    } else {
        D_00388818 = 0;
        D_00388814 = 1;
        D_0038881C = 1;
    }
    if (func_00346230(D_0035C310) != -1) {
        D_00388818 = 0;
        D_00388814 = 2;
        D_0038881C = 0;
    }
    if (func_001065E0(D_0035C330, argc, argv)) D_00388818 = 1;
    if (func_001065E0(D_0035C340, argc, argv)) D_00388818 = 0;
    D_0038880C = 2;
    D_0038883C = D_0035C350;
    if (argv[0]) {
        if (func_00336228(argv[0], func_00114160(D_0035C350)) == 0) {
            D_0038880C = 2;
            D_0038883C = D_0035C350;
        } else if (func_00336228(argv[0], func_00114160(D_0035C360)) == 0) {
            D_0038880C = 2;
            D_0038883C = D_0035C360;
        } else if (func_00336228(argv[0], func_00114160(D_0035C370)) == 0) {
            D_0038880C = 3;
            D_0038883C = D_0035C370;
        } else if (func_00336228(argv[0], func_00114160(D_0035C380)) == 0) {
            D_0038880C = 5;
            D_0038883C = D_0035C380;
        } else if (func_00336228(argv[0], func_00114160(D_0035C390)) == 0) {
            D_0038880C = 6;
            D_0038883C = D_0035C390;
        } else if (func_00336228(argv[0], func_00114160(D_0035C3A0)) == 0) {
            D_0038880C = 4;
            D_0038883C = D_0035C3A0;
        }
    }
    char* lang = func_001064B8(D_0035C3B0, argc, argv);
    if (lang) {
        if (func_00336228(lang, D_00388F58) == 0) {
            D_0038880C = 2;
            D_0038883C = D_0035C350;
        } else if (func_00336228(lang, D_00388F60) == 0) {
            D_0038880C = 3;
            D_0038883C = D_0035C370;
        } else if (func_00336228(lang, D_00388F68) == 0) {
            D_0038880C = 5;
            D_0038883C = D_0035C380;
        } else if (func_00336228(lang, D_00388F70) == 0) {
            D_0038880C = 6;
            D_0038883C = D_0035C390;
        } else if (func_00336228(lang, D_00388F78) == 0) {
            D_0038880C = 4;
            D_0038883C = D_0035C3A0;
        }
    }
    D_0038882C = 1;
    D_00388830 = 60;
    D_00388810 = 0;
    if (argv[0]) {
        char buf[64];
        func_00332088(buf, argv[0], 12);
        buf[12] = 0;
        if (func_00336228(buf, D_0035C3C0) == 0) {
            D_0038882C = 0;
            D_00388830 = 50;
        }
    }
}
