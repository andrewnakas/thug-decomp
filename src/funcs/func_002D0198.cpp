struct Pool_002D0198 {
    char pad[0x104];
    int m104;
};

struct Data_002D0198 {
    char pad[0x18];
    char m18[0x40];
    int m58;
    int m5C;
};

struct Mgr_002D0198 {
    char pad[0xC];
    void* mC;
};

extern Pool_002D0198* D_00388A70;
extern Mgr_002D0198* D_00392068;
extern char D_00392B20[];
extern char D_0037B5B0[];
extern char D_0037B650[];
extern char D_0037B670[];
extern char D_00392B30[];
extern char D_00392B38[];
extern char D_0037B688[];
extern char D_0037B620[];
extern char D_0037B698[];
extern char D_0037B6B0[];
extern char D_0037B6C8[];
extern char D_0037B6E0[];
extern char D_00392B40[];
extern char D_00392B48[];
extern char D_0037B6F8[];
extern char D_0037B708[];
extern char D_00392B50[];
extern char D_00392B58[];
extern char D_0037B720[];
extern char D_0037B730[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E90A8(void* arr, int i, int v);
extern "C" void func_001E8DE8(void* arr, int flags);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7318(void* p, char* name, float v);
extern "C" void func_001E76D8(void* p, char* name, void* arr);
extern "C" void func_001E7860(void* p, char* name, void* s);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" char* func_002D3D40(void* self, char* name);
extern "C" int func_002D7EB8(void* p);
extern "C" int func_002D8158(void* p);
extern "C" int func_002D8160(void* p, int v);
extern "C" int func_002D8210(void* p);

void func_002D0198(void* self, Data_002D0198* d)
{
    Mgr_002D0198* g = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m104);
    void* t = func_001E6978(func_001190D0(8));
    void* s = func_001E6978(func_001190D0(8));
    void* arr = func_001E8DD0(func_00122CF8(0x10));
    void* u = func_001E6978(func_001190D0(8));
    func_001E7138(s, D_00392B20, func_002D3D40(self, d->m18));
    func_001E8E98(arr, 4, 1);
    if (d->m58 && func_002D7EB8(g->mC)) {
        if (d->m58 == func_002D8158(g->mC) || func_002D8160(g->mC, d->m58)) {
            if (func_002D8158(g->mC) == d->m58) {
                func_001E90A8(arr, 0, 0);
                func_001E90A8(arr, 1, 0);
                func_001E90A8(arr, 2, 0x80);
                func_001E90A8(arr, 3, 0x80);
                func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B650));
            } else {
                func_001E90A8(arr, 0, 0x80);
                func_001E90A8(arr, 1, 0x80);
                func_001E90A8(arr, 2, 0);
                func_001E90A8(arr, 3, 0x80);
                func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B670));
            }
        } else {
            func_001E90A8(arr, 0, 0);
            func_001E90A8(arr, 1, 0x80);
            func_001E90A8(arr, 2, 0);
            func_001E90A8(arr, 3, 0x80);
            func_001E7268(t, D_00392B30, d->m58);
            func_001E7138(t, D_00392B38, d->m18);
            func_001E7138(t, D_0037B688, func_002D3D40(self, d->m18));
            func_001E7860(s, D_0037B620, t);
            if (func_002D8210(g->mC) < 30)
                func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B698));
            else
                func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B6B0));
        }
    } else {
        func_001E90A8(arr, 0, 0x80);
        func_001E90A8(arr, 1, 0x80);
        func_001E90A8(arr, 2, 0x80);
        func_001E90A8(arr, 3, 0x80);
        if (func_002D7EB8(g->mC))
            func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B6C8));
        else
            func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B6E0));
    }
    func_001E7268(s, D_00392B40, (int)(d->m5C * 0.003448275849f));
    func_001E73C8(s, D_00392B48, func_001F0D78(d->m18));
    func_001E73C8(s, D_0037B6F8, func_001F0D78(D_0037B708));
    func_001E7318(s, D_00392B50, 1.1f);
    func_001E76D8(u, D_00392B58, arr);
    func_001E76D8(s, D_00392B58, arr);
    func_001E7860(s, D_0037B720, u);
    func_001F0370(D_0037B730, s, 0, 0);
    if (arr) func_001E8DE8(arr, 3);
    if (t) func_001E6AE8(t, 3);
    if (s) func_001E6AE8(s, 3);
    if (u) func_001E6AE8(u, 3);
    func_0010A9B0(D_00388A70);
}
