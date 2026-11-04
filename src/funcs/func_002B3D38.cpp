struct Pool_002B3D38 {
    char pad0[0xE4];
    int mE4;
};

struct Info_002B3D38 {
    char m0[0x18];
    char m18[0x64 - 0x18];
    char m64[0x9C - 0x64];
    int m9C;
    char padA0[0xAC - 0xA0];
    char* mAC;
};

extern Pool_002B3D38* D_00388A70;
extern char D_00379A10[];
extern char D_00379A30[];
extern char D_00392450[];
extern char D_00392458[];
extern char D_00379A58[];
extern char D_00392460[];
extern char D_00392468[];
extern char D_00379A70[];
extern char D_00379A88[];
extern char D_00379AA0[];
extern char D_00379AB8[];
extern char D_00379AC8[];
extern char D_00379AE8[];
extern char D_00379B00[];
extern char D_00379B10[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_002B3C88(void* s);
extern "C" int func_002A1A28(void* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E73C8(void* p, char* name, char* v);
extern "C" void func_001E7860(void* p, char* name, void* v);
extern "C" char* func_001F0D78(char* s);
extern "C" void func_00103F28(const char* fmt, ...);

extern "C" void func_002B3D38(void* s, Info_002B3D38* o)
{
    func_0010A950(D_00388A70, D_00388A70->mE4);
    if (!func_002B3C88(s)) func_001F0370(D_00379A10, 0, 0, 0);
    func_001F0370(D_00379A30, 0, 0, 0);
    void* p = func_001E6978(func_001190D0(8));
    func_001E7138(p, D_00392450, o->m18);
    func_001E7138(p, D_00392458, o->m64);
    func_00103F28(D_00379A58, o->m64);
    char* name = func_002A1A28(s) ? o->mAC : o->m0;
    func_001E73C8(p, D_00392460, name);
    func_001E73C8(p, D_00392468, func_001F0D78(D_00379A70));
    func_001E73C8(p, D_00379A88, func_001F0D78(D_00379AA0));
    func_001E73C8(p, D_00379AB8, func_001F0D78(D_00379AC8));
    void* q = func_001E6978(func_001190D0(8));
    func_001E73C8(q, D_00392460, name);
    func_001E7860(p, D_00379AE8, q);
    func_001E7860(p, D_00379B00, q);
    func_001F0370(D_00379B10, p, 0, 0);
    o->m9C = 1;
    if (p) func_001E6AE8(p, 3);
    if (q) func_001E6AE8(q, 3);
    func_0010A9B0(D_00388A70);
}
