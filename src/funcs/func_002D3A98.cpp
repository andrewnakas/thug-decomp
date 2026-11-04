extern char D_00392B20[];
extern char D_0037BD40[];
extern char D_0037BD50[];
extern char D_0037B920[];

struct Sub_002D3A98 {
    char pad[0x158];
    void* m158;
};

struct Mgr_002D3A98 {
    char pad[4];
    Sub_002D3A98* m4;
};

struct Pool_002D3A98 {
    char pad[0x104];
    int m104;
};

extern Mgr_002D3A98* D_00392068;
extern Pool_002D3A98* D_00388A70;
extern "C" bool func_001E8890(void* s, char* name, char** out, int a);
extern "C" int func_001E87B8(void* s, char* name);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_00306870(void* p, int a, char* s, int b);

bool Cmd_002D3A98(void* params)
{
    char buf[1024];
    char* str;
    Mgr_002D3A98* mgr = D_00392068;
    if (func_001E8890(params, D_00392B20, &str, 0)) {
        if (func_001E87B8(params, D_0037BD40)) {
            func_003331D0(buf, D_0037BD50, str);
            void* s = func_001E6978(func_001190D0(8));
            func_001E7138(s, D_00392B20, buf);
            func_001F0370(D_0037B920, s, 0, 0);
            if (s)
                func_001E6AE8(s, 3);
        } else {
            func_0010A950(D_00388A70, D_00388A70->m104);
            func_00306870(mgr->m4->m158, 1, str, 0);
            func_0010A9B0(D_00388A70);
        }
    }
    return true;
}
