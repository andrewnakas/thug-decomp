struct Heap_002CFF98 {
    char pad[0x104];
    int m104;
};

struct Obj_002CFF98 {
    char pad0[0x18];
    char m18[0x5C - 0x18];
    int m5C;
    int m60;
    char pad64[0x6C - 0x64];
    int m6C;
    int m70;
};

extern Heap_002CFF98* D_00388A70;
extern "C" void func_0010A950(Heap_002CFF98* p, int v);
extern "C" void func_0010A9B0(Heap_002CFF98* p);
extern "C" char* func_001E54B8(char* s, int v);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E73C8(void* p, char* s, int v);
extern "C" void func_001E7268(void* p, char* name, void* v);
extern "C" void func_001E7860(void* p, char* name, void* v);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern char D_0037B580[];
extern char D_0037B590[];
extern char D_0037B5A0[];
extern char D_00392B20[];
extern char D_0037B5B0[];
extern char D_0037B5C8[];
extern char D_0037B5E0[];
extern char D_0037B5F8[];
extern char D_0037B608[];
extern char D_00392B28[];
extern char D_0037B620[];
extern char D_0037B638[];

struct Mgr_002CFF98 {
    void Show(Obj_002CFF98* o, void* arg);
};

void Mgr_002CFF98::Show(Obj_002CFF98* o, void* arg)
{
    char buf[64];
    func_0010A950(D_00388A70, D_00388A70->m104);
    if (o->m6C) {
        func_003331D0(buf, D_0037B580, o->m18, o->m5C, o->m60, func_001E54B8(D_0037B590, 0));
    } else {
        func_003331D0(buf, D_0037B5A0, o->m18, o->m5C, o->m60);
    }
    void* s1 = func_001E6978(func_001190D0(8));
    func_001E7138(s1, D_00392B20, buf);
    if (o->m6C || o->m70) {
        func_001E7360(s1, 0, 0x1D944426);
        func_001E73C8(s1, D_0037B5B0, func_001F0D78(D_0037B5C8));
    } else {
        func_001E73C8(s1, D_0037B5B0, func_001F0D78(D_0037B5E0));
        func_001E73C8(s1, D_0037B5F8, func_001F0D78(D_0037B608));
    }
    void* s0 = func_001E6978(func_001190D0(8));
    func_001E7268(s0, D_00392B28, arg);
    if (!o->m6C && !o->m70) {
        func_001E7860(s1, D_0037B620, s0);
    }
    func_001F0370(D_0037B638, s1, 0, 0);
    if (s1) func_001E6AE8(s1, 3);
    if (s0) func_001E6AE8(s0, 3);
    func_0010A9B0(D_00388A70);
}
