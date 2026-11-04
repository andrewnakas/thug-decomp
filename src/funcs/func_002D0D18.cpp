struct Heap_002D0D18 {
    char pad0[0x104];
    void* m104;
};

extern Heap_002D0D18* D_00388A70;
extern char D_00392B68[];
extern char D_00392B20[];
extern char D_0037B920[];
extern "C" void func_0010A950(void* h, void* ctx);
extern "C" void func_0010A9B0(void* h);
extern "C" int func_002D3D40(int a, int b);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int flags);

void Run_002D0D18(void* a0, void* a1, int a, int b, int t0, int t1)
{
    func_0010A950(D_00388A70, D_00388A70->m104);
    char buf[0x400];
    func_003331D0(buf, D_00392B68, func_002D3D40(t1, a), b);
    void* s = func_001E6978(func_001190D0(8));
    func_001E7138(s, D_00392B20, buf);
    func_001F0370(D_0037B920, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);
    func_0010A9B0(D_00388A70);
}
