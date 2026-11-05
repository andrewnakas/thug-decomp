struct Heap_00210DD0 {
    char pad0[0x11C];
    void* m_11C;
};

extern Heap_00210DD0* D_00388A70;
extern char D_0038F468[];
extern char D_0038F470[];

extern "C" void func_0010A950(Heap_00210DD0* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_00210DD0* mgr);
extern "C" bool func_001E8890(void* params, const char* name, const char** out, int required);
extern "C" void func_00131B80(const char* a, const char* b);

bool func_00210DD0(void* params)
{
    const char* a = 0;
    const char* b = 0;
    func_001E8890(params, D_0038F468, &a, 0);
    func_001E8890(params, D_0038F470, &b, 0);
    if (a && b) {
        func_0010A950(D_00388A70, D_00388A70->m_11C);
        func_00131B80(a, b);
        func_0010A9B0(D_00388A70);
    }
    return true;
}
