struct Info_00222A88 {
    int m_0;
    unsigned int m_value;
    unsigned int m_name;
    int m_isInt;
};

struct Script_00222A88 {
    char pad0[0x18];
    void* m_params;
};

extern void* D_0038FC78;
extern char D_0038F8F0[];
extern char D_00371A78[];
extern char D_00371A90[];
extern char D_0038F910[];

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void* func_0022E368(void* mgr, int a);
extern "C" void func_00261FB0(Info_00222A88* out, void* obj, int index);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_00222A88(void* params, Script_00222A88* script)
{
    Info_00222A88 info;
    int index;
    func_001E7E58(params, D_0038F8F0, &index, 1);
    func_00261FB0(&info, func_0022E368(D_0038FC78, 0), index);
    func_001E73C8(script->m_params, D_00371A78, info.m_name);
    if (info.m_isInt)
        func_001E7268(script->m_params, D_00371A90, info.m_value);
    else
        func_001E73C8(script->m_params, D_00371A90, info.m_value);
    func_001E7268(script->m_params, D_0038F910, info.m_isInt);
    return true;
}
