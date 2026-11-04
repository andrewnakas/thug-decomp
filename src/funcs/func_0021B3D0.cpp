struct Mgr_0021B3D0 {
    char pad0[0x24];
    void* m_24;
};

struct Script_0021B3D0 {
    char pad0[0x18];
    void* m_params;
};

extern Mgr_0021B3D0* D_0038FC78;
extern char D_0038F7C8[];
extern char D_0038F7D0[];

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" const char* func_00263A80(void* mgr, int i);
extern "C" int func_003331D0(char* buf, const char* fmt, const char* s);
extern "C" void func_001E7A30(void* params, unsigned int name, int type, const char* value);

bool func_0021B3D0(void* params, Script_0021B3D0* script)
{
    char buf[0x70];
    void* mgr = D_0038FC78->m_24;
    int index = 0;
    func_001E7DE8(params, 0, &index, 0);
    func_003331D0(buf, D_0038F7C8, func_00263A80(mgr, index));
    func_001E7A30(script->m_params, 0xC661FE79, 3, buf);
    func_001E7A30(script->m_params, 0xA43DC969, 3, D_0038F7D0);
    return true;
}
