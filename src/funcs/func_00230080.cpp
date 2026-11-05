struct Heap_00230080 {
    char pad[0xDC];
    int m_DC;
};

struct Mgr_00230080 {
    char pad[0x8C];
    unsigned int m_8C;
};

extern Heap_00230080* D_00388A70;
extern Mgr_00230080* D_0038FC78;
extern void* D_00392068;
extern "C" void func_0010A950(Heap_00230080* heap, int ctx);
extern "C" void func_0010A9B0(Heap_00230080* heap);
extern "C" int func_002A1B30(void* a);
extern "C" void func_0010B8E0(Heap_00230080* heap);
extern "C" void func_0010B768(Heap_00230080* heap, int n);

bool Cmd_00230080(void* params, void* script)
{
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    int n;
    if (D_0038FC78->m_8C == 0x5C8F5D66) {
        n = 2;
    } else {
        n = func_002A1B30(D_00392068);
    }
    if (n >= 2) {
        func_0010B8E0(D_00388A70);
        func_0010B768(D_00388A70, n);
    }
    func_0010A9B0(D_00388A70);
    return true;
}
