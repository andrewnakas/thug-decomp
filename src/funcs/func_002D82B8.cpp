extern void* D_00392068;
extern char D_00392D28[];
extern char D_0037C388[];
extern char D_0037C5B8[];

extern "C" unsigned int func_0010FC30();
extern "C" int func_002A6070(void* m);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" int func_001F0D78(char* s);
extern "C" void func_00203068(int id, int key, void* p);
extern "C" void func_001E6AE8(void* p, int v);

int func_002D82B8()
{
    char buf[32];
    void* m = D_00392068;
    unsigned int t = func_0010FC30();
    int id = func_002A6070(m);
    void* p = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_00392D28, t);
    func_001E7138(p, D_0037C388, buf);
    func_00203068(id, func_001F0D78(D_0037C5B8), p);
    if (p) {
        func_001E6AE8(p, 3);
    }
    return 1;
}
