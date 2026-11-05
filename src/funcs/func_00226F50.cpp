struct Script_00226F50 {
    char pad0[0x18];
    void* m_params;
};

extern void* D_00388EFC;

extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void* func_00112FB8(void* mgr, int a, int b);
extern "C" int func_001132C0(void* card);

bool func_00226F50(void* params, Script_00226F50* script)
{
    func_001E7200(script->m_params, 0x0C37C363, 0);
    func_001E7200(script->m_params, 0x0855B2FC, 1000000);
    void* card = func_00112FB8(D_00388EFC, 0, 0);
    if (card) {
        void* out = script->m_params;
        func_001E7200(out, 0x0C37C363, func_001132C0(card));
        return true;
    }
    return false;
}
