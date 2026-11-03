extern char D_003794C0[];
extern char D_003922F8[];
extern char D_003794D0[];

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* s);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

struct Info_002B08B0 {
    signed char m0;
    char m1[0x10];
    char m11[0x10];
};

struct Obj_002B08B0 {
    Info_002B08B0* m0;
    bool Notify();
};

bool Obj_002B08B0::Notify()
{
    char buf[256];
    Info_002B08B0* info = m0;
    void* p = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_003794C0, info->m0 + 2, info->m1, info->m11);
    func_001E7138(p, D_003922F8, buf);
    func_001F0370(D_003794D0, p, 0, 0);
    if (p) {
        func_001E6AE8(p, 3);
    }
    return true;
}
