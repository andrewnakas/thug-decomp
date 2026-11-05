struct Heap_0013A800 {
    char pad[0x11C];
    void* m11C;
};

struct Child_0013A800 {
    int m0;
    int m4;
};

extern "C" int func_001E8870(void* params, unsigned int id, char** out, int req);
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" Child_0013A800* func_001394A0(void* node, char* name);
extern "C" Child_0013A800* func_00138F58(void* node, char* name, int a, int b, int c);
extern "C" bool func_001390E0(void* node, Child_0013A800* c);
extern "C" void func_0010A950(Heap_0013A800* heap, void* sub);
extern "C" void func_0010A9B0(Heap_0013A800* heap);
extern Heap_0013A800* D_00388A70;
extern void* D_00393EF8;
extern int D_0038881C;
extern int D_00388818;

bool Cmd_0013A800(void* params, void* script)
{
    char* name;
    func_001E8870(params, 0, &name, 0);
    if (!name[0])
        return false;
    Child_0013A800* c = func_001394A0(D_00393EF8, name);
    int f = func_001E8708(params, 0xD5928F25);
    if (!c) {
        c = func_00138F58(D_00393EF8, name, 1, 1, f);
    } else {
        if (D_0038881C)
            return c != 0;
        if (D_00388818)
            func_0010A950(D_00388A70, D_00388A70->m11C);
        f = c->m4;
        func_001390E0(D_00393EF8, c);
        c = func_00138F58(D_00393EF8, name, 1, 1, f);
        if (D_00388818)
            func_0010A9B0(D_00388A70);
    }
    return c != 0;
}
