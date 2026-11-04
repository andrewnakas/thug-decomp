extern "C" void* func_00240850();
extern "C" void func_001E77D0(void* s, unsigned int crc, void* v);
extern "C" void* func_001E6E90(void* list, void* prev);
extern "C" void func_001E7200(void* s, unsigned int crc, int v);

struct Mgr_00243738 {
    char pad0[0x54];
    void* m_54;
};

struct Script_00243738 {
    char pad0[0x18];
    void* m_18;
};

bool Cmd_00243738(void* params, Script_00243738* script)
{
    int n = 0;
    void* list = ((Mgr_00243738*)func_00240850())->m_54;
    func_001E77D0(script->m_18, 0x3B1F59E0, list);
    void* p = func_001E6E90(list, 0);
    while (p) {
        p = func_001E6E90(list, p);
        n++;
    }
    func_001E7200(script->m_18, 0xEB8DD330, n);
    return true;
}
