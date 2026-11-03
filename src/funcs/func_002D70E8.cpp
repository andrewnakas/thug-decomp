struct Obj_002D70E8_A {
    char pad0[0x108];
    int m108;
};

extern Obj_002D70E8_A* D_00388A70;
extern void* D_00392068;
extern char D_0037C378[];
extern char D_0037C388[];
extern char D_0037C398[];
extern char D_0037C3B0[];

extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" void func_003267F8();
extern "C" void func_00326938();
extern "C" int func_002A6070(void* m);
extern "C" int func_001F0D78(char* s);
extern "C" int func_00202F78(int id, int a, int b);
extern "C" void func_002D6FC0();
extern "C" void func_002E8870(void* p, char* s, int a, int b, int c, int d, void (*cb)(), void* arg);

void func_002D70E8(void* p)
{
    void* m = D_00392068;
    func_0010A950(D_00388A70, D_00388A70->m108);
    func_003267F8();
    int id = func_002A6070(m);
    int a = func_00202F78(id, func_001F0D78(D_0037C378), func_001F0D78(D_0037C388));
    int b = func_00202F78(id, func_001F0D78(D_0037C398), func_001F0D78(D_0037C388));
    func_002E8870(p, D_0037C3B0, a, b, 1, 0, func_002D6FC0, p);
    func_00326938();
    func_0010A9B0(D_00388A70);
}
