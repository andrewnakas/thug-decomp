struct Mgr_0021E360 {
    char m_pad0[0x39C];
    void* m39C;
};

struct Script_0021E360 {
    char m_pad0[0x18];
    void* m18;
};

extern Mgr_0021E360* D_0038FC78;
extern char D_0038F7D8[];
extern "C" int func_0025FDB0(void* p);
extern "C" void func_001E70C0(void* p, unsigned int name, char* v);
extern "C" void func_001E7360(void* p, unsigned int name, int v);

bool Cmd_0021E360(void* params, Script_0021E360* script)
{
    int v = func_0025FDB0(D_0038FC78->m39C);
    if (v) {
        func_001E7360(script->m18, 0xA1DC81F9, v);
        return true;
    }
    func_001E70C0(script->m18, 0xA1DC81F9, D_0038F7D8);
    return false;
}
