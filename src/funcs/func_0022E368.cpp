struct Mgr_0022E368 {
    char pad[0x80];
    void* m_80;
    void* GetPlayer(void* params);
};

extern char D_0038FCC0[];
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_002629A8(void* a, int index);
extern "C" void* func_00262990(void* a);

void* Mgr_0022E368::GetPlayer(void* params)
{
    int index;
    if (params && func_001E7E58(params, D_0038FCC0, &index, 0)) {
        return func_002629A8(m_80, index);
    }
    return func_00262990(m_80);
}
