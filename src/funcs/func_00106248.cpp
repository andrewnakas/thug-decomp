extern "C" int func_003331D0(char*, const char*, ...);
extern "C" void func_001061A0();
extern "C" void func_0031D098();
extern "C" void func_00103F28(const char*, ...);
extern "C" void func_003209E0(const char*, int, const char**);

extern int D_0038882C;
extern int D_0038880C;
extern char D_00388738[], D_0035AAF0[], D_0035AB00[], D_00388740[];
extern char D_0035AB18[], D_0035AB30[], D_0035AB48[], D_0035AB60[], D_0035AB78[];
extern char D_00388748[], D_0035AB90[], D_0035ABA0[], D_0035ABC8[];

int func_00106248(int arg)
{
    char path[0x70];
    const char* argv[4];
    func_003331D0(path, D_00388738, arg);
    func_001061A0();
    func_0031D098();
    argv[0] = D_0035AAF0;
    if ((D_0038882C ^ 1) == 0) {
        argv[1] = D_0035AB00;
        argv[2] = D_00388740;
        argv[3] = D_00388740;
    } else {
        switch (D_0038880C) {
        case 3: argv[1] = D_0035AB18; break;
        case 5: argv[1] = D_0035AB30; break;
        case 6: argv[1] = D_0035AB48; break;
        case 4: argv[1] = D_0035AB60; break;
        case 2: default: argv[1] = D_0035AB78; break;
        }
        argv[2] = D_00388748;
        argv[3] = D_0035AB90;
    }
    func_00103F28(D_0035ABA0, path, argv[0], argv[1], argv[2], argv[3]);
    func_003209E0(path, 4, argv);
    func_00103F28(D_0035ABC8);
    return 1;
}
