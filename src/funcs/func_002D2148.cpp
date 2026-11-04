struct Heap_002D2148 {
    char pad[0x104];
    int m104;
};

extern Heap_002D2148* D_00388A70;
extern void* D_00392068;
extern char D_0037B7F8[];
extern char D_0037B808[];
extern char D_0037BB20[];
extern char D_0037BB40[];
extern char D_00392B60[];
extern "C" void func_0010A950(Heap_002D2148* p, int v);
extern "C" void func_0010A9B0(Heap_002D2148* p);
extern "C" void* func_002A6070(void* m);
extern "C" int func_001F0D78(const char* s);
extern "C" int func_00202F78(void* p, int a, int b);
extern "C" int func_00103F28(char* fmt, ...);
extern "C" unsigned int func_0010FC30();
extern "C" void func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_00305638(void* o, char* s);
extern "C" void func_002FF990(char* buf, void* arg);

void func_002D2148(void* o, int mode, void* arg)
{
    char buf[0x80];
    func_0010A950(D_00388A70, D_00388A70->m104);
    if (mode == 0) {
        int v = func_00202F78(func_002A6070(D_00392068), func_001F0D78(D_0037B7F8), func_001F0D78(D_0037B808));
        func_00103F28(D_0037BB20, arg);
        func_003331D0(buf, D_00392B60, func_0010FC30(), v);
        func_00305638(o, buf);
    } else if (mode == 1) {
        func_00103F28(D_0037BB40, arg);
        func_002FF990(buf, arg);
        func_00305638(o, buf);
    }
    func_0010A9B0(D_00388A70);
}
