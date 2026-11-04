extern char D_00392DA8[];
extern char D_00392DB0[];
extern char D_0037C308[];
extern char D_00392DB8[];
extern char D_0037C318[];
extern char D_00392D98[];
extern char D_00392DA0[];
extern char D_00392DC0[];
extern char D_0037C3C0[];
extern char D_0037C3D0[];
extern char D_0037C3E0[];
extern char D_0037C3F0[];
extern char D_0037C400[];
extern char D_0037C410[];
extern char D_0037C420[];
extern char D_0037C440[];
extern char D_0037C450[];
extern char D_0037C468[];
extern char D_0037C480[];
extern char D_0037C498[];
extern char D_0037C4B0[];
extern char D_0037C4C0[];
extern char D_0037C4D0[];
extern char D_00392DC8[];
extern char D_0037C4E8[];

struct Info_002D72E8 {
    char pad[0x18];
    char m18[0x38 - 0x18];
    int m38;
    int m3C;
    char pad40[4];
    int m44;
    int m48;
    int m4C;
    char m50[0x100];
    char m150[4];
};

struct Pool_002D72E8 {
    char pad[0x104];
    int m104;
};

extern Pool_002D72E8* D_00388A70;
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" char* func_00336628(char* s);
extern "C" void func_001E7360(void* s, int name, int v);
extern "C" void func_001E7860(void* s, char* name, void* t);
extern "C" void func_001E7318(void* s, char* name, float v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

void func_002D72E8(void* self, Info_002D72E8* info, int a2, int a3)
{
    char buf[1024];
    func_0010A950(D_00388A70, D_00388A70->m104);
    void* s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, info->m18);
    func_001E7138(s, D_00392DA8, info->m18);
    func_001E7138(s, D_00392DB0, info->m150);
    func_001E7138(s, D_0037C308, info->m50);
    func_001E73C8(s, D_00392DB8, func_001F0D78(D_0037C318) + info->m38);
    if (a2 || a3) {
        void* t = func_001E6978(func_001190D0(8));
        func_001E7268(t, D_00392D98, info->m38);
        func_001E7138(t, D_00392DA0, func_00336628(buf));
        func_001E7138(t, D_00392DB0, info->m150);
        func_001E7138(t, D_0037C308, info->m50);
        func_001E7268(t, D_00392DC0, info->m44);
        func_001E7268(t, D_0037C3C0, info->m48);
        func_001E7268(t, D_0037C3D0, info->m4C);
        if (a3)
            func_001E7360(t, 0, func_001F0D78(D_0037C3E0));
        if (a2) {
            if (info->m3C == 2)
                func_001E7360(t, 0, func_001F0D78(D_0037C3F0));
            func_001E7360(t, 0, func_001F0D78(D_0037C400));
        } else {
            func_001E73C8(t, D_0037C410, func_001F0D78(D_0037C420));
            func_001E73C8(t, D_0037C440, func_001F0D78(D_0037C450));
        }
        func_001E7860(s, D_0037C468, t);
        func_001E73C8(s, D_0037C480, func_001F0D78(D_0037C498));
    } else {
        func_001E73C8(s, D_0037C480, func_001F0D78(D_0037C4B0));
    }
    func_001E73C8(s, D_0037C4C0, func_001F0D78(D_0037C4D0));
    if (a2)
        func_001E7318(s, D_00392DC8, 1.1f);
    func_001F0370(D_0037C4E8, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);
    func_0010A9B0(D_00388A70);
}
