extern char D_003799C0[];
extern char D_003799D0[];
extern char D_003799E0[];
extern char D_003799F8[];

struct Heap_002B3A78 {
    char pad[0x104];
    int m104;
};

struct Mgr_002B3A78 {
    char pad0[4];
    void* m4;
    char pad8[4];
    void* mC;
    void Report();
};

extern Heap_002B3A78* D_00388A70;
extern void* D_0038EB78;
extern "C" void func_0010A950(Heap_002B3A78* p, int v);
extern "C" void func_0010A9B0(Heap_002B3A78* p);
extern "C" void func_002D2C40(void* p);
extern "C" int func_002D7EB8(void* p);
extern "C" void* func_002A6070(Mgr_002B3A78* m);
extern "C" int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* p, int crc);
extern "C" bool func_001E8890(void* p, char* name, char** out, int v);
extern "C" void* func_002D3D30(void* p);
extern "C" int func_001FA618(void* p);
extern "C" int func_00305F68(void* p);
extern "C" int func_002D30A8(void* p);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" int func_001E54B8(char* s, int v);
extern "C" void func_002D8248(void* p, int a, int b, char* c);

void Mgr_002B3A78::Report()
{
    char buf[0x400];
    char* str;
    void* net = D_0038EB78;
    func_0010A950(D_00388A70, D_00388A70->m104);
    func_002D2C40(m4);
    if (func_002D7EB8(mC)) {
        func_001E8890(func_00202EF8(func_002A6070(this), func_001F0D78(D_003799C0)), D_003799D0, &str, 1);
        if (func_002D3D30(m4)) {
            char* fmt = D_003799E0;
            int a = func_001FA618(net);
            int b = func_00305F68(func_002D3D30(m4));
            func_003331D0(buf, fmt, a, b, 0x141E, str, func_002D30A8(m4));
        }
        func_002D8248(mC, 2, func_001E54B8(D_003799F8, 0), buf);
    }
    func_0010A9B0(D_00388A70);
}
