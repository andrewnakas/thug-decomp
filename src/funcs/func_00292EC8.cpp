extern char D_004530D0[];
extern char D_003772C8[];
extern char D_00377300[];
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001F0D78(char* s);

struct Obj_00292EC8 {
    char pad0[0x2A8];
    int m2A8;
    int NameCrc(int k);
};

int Obj_00292EC8::NameCrc(int k)
{
    if (k == 0) {
        func_003331D0(D_004530D0, D_003772C8, m2A8);
    } else {
        if (k < 2)
            return 0;
        func_003331D0(D_004530D0, D_00377300, m2A8, k - 2);
    }
    return func_001F0D78(D_004530D0);
}
