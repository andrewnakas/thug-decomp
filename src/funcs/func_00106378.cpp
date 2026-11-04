extern "C" void func_001061A0();
extern "C" void func_0031D098();
extern "C" void func_00103F28(const char*, ...);
extern "C" void func_00318A40(int);
extern "C" void func_003209E0(const char*, int, const char**);

extern int D_00388824;
extern int D_0038ED78;
extern char D_0035AC38[], D_0035AC58[], D_0035AC80[];
extern char D_003953E8[], D_00395468[];

void func_00106378()
{
    func_001061A0();
    for (;;) {
        func_0031D098();
        if (D_00388824) {
            func_00103F28(D_0035AC38);
            func_00318A40(D_0038ED78);
        } else {
            const char* argv[1];
            func_0031D098();
            argv[0] = D_00395468;
            func_00103F28(D_0035AC58, D_003953E8, D_00395468);
            func_003209E0(D_003953E8, 1, argv);
        }
        func_00103F28(D_0035AC80);
    }
}
