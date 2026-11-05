extern char D_00390740[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" int func_002521A0();
extern "C" int func_00100030(int n);

struct Obj_002521F8 {
    int m0;
    int m4;
    int m8;
    int mC;
    char pad10[0x200];
    char m210[0x200];
    int m410[8];
    char pad430[4];
    int m434;
    void Fn();
};

void Obj_002521F8::Fn()
{
    m4 = 0;
    m8 = 0;
    mC = 0;
    func_003331D0(m210, D_00390740);
    for (int i = 7; i >= 0; i--) m410[i] = 0;
    m434 = func_00100030(func_002521A0());
}
