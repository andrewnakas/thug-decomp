struct Pool_002D0858 {
    char pad[0x104];
    int m104;
};

struct Data_002D0858 {
    char pad[0x18];
    char m18[0x40];
    int m58;
};

extern Pool_002D0858* D_00388A70;
extern char D_00392B20[];
extern char D_0037B5B0[];
extern char D_0037B790[];
extern char D_0037B6F8[];
extern char D_0037B7A0[];
extern char D_00392B30[];
extern char D_00392B38[];
extern char D_0037B688[];
extern char D_0037B620[];
extern char D_0037B7B8[];
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int mode);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E7268(void* p, char* name, int v);
extern "C" void func_001E73C8(void* p, char* name, int v);
extern "C" void func_001E7860(void* p, char* name, void* s);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" char* func_002D3D40(void* self, char* name);

void func_002D0858(void* self, Data_002D0858* d)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    void* s = func_001E6978(func_001190D0(8));
    func_001E7138(s, D_00392B20, func_002D3D40(self, d->m18));
    func_001E73C8(s, D_0037B5B0, func_001F0D78(D_0037B790));
    func_001E73C8(s, D_0037B6F8, func_001F0D78(D_0037B7A0));
    void* t = func_001E6978(func_001190D0(8));
    func_001E7268(t, D_00392B30, d->m58);
    func_001E7138(t, D_00392B38, d->m18);
    func_001E7138(t, D_0037B688, func_002D3D40(self, d->m18));
    func_001E7860(s, D_0037B620, t);
    func_001F0370(D_0037B7B8, s, 0, 0);
    if (s) func_001E6AE8(s, 3);
    if (t) func_001E6AE8(t, 3);
    func_0010A9B0(D_00388A70);
}
