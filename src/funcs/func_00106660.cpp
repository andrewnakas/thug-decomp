extern "C" void func_001141B8(int, char**);
extern "C" bool func_001065E0(const char*, int, char**);
extern "C" const char* func_001064B8(const char*, int, char**);
extern "C" char* func_00331A9C(char*, const char*);
extern "C" int func_003331D0(char*, const char*, ...);
extern "C" void func_00103F28(const char*, ...);
extern "C" int func_00331950(const char*, const char*);

extern int D_0038881C;
extern int D_00388820;
extern int D_0038882C;
extern int D_00388830;
extern char D_00388840[], D_00388848[], D_0035ACB0[], D_003953E8[], D_00395468[];
extern char D_00388850[], D_0035ACC0[], D_0035ACF8[], D_00388858[], D_00388860[];
extern char D_0035AD08[], D_00388868[], D_00388870[];

void func_00106660(int argc, char** argv)
{
    func_001141B8(argc, argv);
    if (func_001065E0(D_00388840, argc, argv))
        D_0038881C = 1;
    if (func_001065E0(D_00388848, argc, argv))
        D_0038881C = 0;
    if (func_001065E0(D_0035ACB0, argc, argv)) {
        D_00388820 = 1;
        if (argc >= 3) {
            func_00331A9C(D_003953E8, argv[2]);
            if (argc >= 4)
                func_00331A9C(D_00395468, argv[3]);
            else
                func_003331D0(D_00395468, D_00388850);
            func_00103F28(D_0035ACC0, D_003953E8, D_00395468);
        }
    }
    if (func_001065E0(D_0035ACF8, argc, argv))
        D_00388820 = 0;
    if (func_001065E0(D_00388858, argc, argv))
        D_0038882C = 0;
    if (func_001065E0(D_00388860, argc, argv))
        D_0038882C = 1;
    const char* rate = func_001064B8(D_0035AD08, argc, argv);
    if (rate) {
        if (func_00331950(rate, D_00388868) == 0)
            D_00388830 = 50;
        if (func_00331950(rate, D_00388870) == 0)
            D_00388830 = 60;
    }
}
