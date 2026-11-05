extern char D_0035BE58[];
extern char D_0035BE68[];
extern int D_00388E18;
extern int D_00388E14;
extern "C" char* func_00106818();
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_00103F28(const char* fmt, ...);

struct Info_00110D48 {
    int m0;
    char pad[0x2C];
};

extern "C" int func_00328438(Info_00110D48* info, const char* name);

extern "C" void func_00110D48()
{
    Info_00110D48 info;
    char path[0x80];
    func_003331D0(path, D_0035BE58, func_00106818());
    while (!func_00328438(&info, path)) {
        func_00103F28(D_0035BE68);
    }
    D_00388E18 = 1;
    D_00388E14 = info.m0;
}
