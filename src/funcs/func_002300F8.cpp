struct Heap_002300F8 {
    char pad0[0xDC];
    void* m_DC;
};

struct Script_002300F8 {
    char pad0[0xCC];
    int m_flags;
};

extern Heap_002300F8* D_00388A70;
extern void* D_0038FC78;

extern "C" void func_0010A950(Heap_002300F8* mgr, void* heap);
extern "C" void func_0010A9B0(Heap_002300F8* mgr);
extern "C" void func_0022E850(void* mgr);

bool func_002300F8(void* params, Script_002300F8* script)
{
    void* mgr = D_0038FC78;
    int saved = 0;
    if (script) {
        saved = script->m_flags & 1;
        script->m_flags &= ~1;
    }
    func_0010A950(D_00388A70, D_00388A70->m_DC);
    func_0022E850(mgr);
    func_0010A9B0(D_00388A70);
    if (script)
        script->m_flags = (script->m_flags & ~1) | saved;
    return true;
}
