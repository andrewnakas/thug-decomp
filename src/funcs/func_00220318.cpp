struct Str_00220318 {
    char m_data[0x10];
};

struct Mgr_00220318 {
    char pad0[0x398];
    void* m_398;
};

struct Script_00220318 {
    char pad0[0x18];
    void* m_params;
};

extern Mgr_00220318* D_0038FC78;
extern char D_00371828[];
extern char D_0038F8A0[];

extern "C" bool func_001E8A50(void* params, const char* name, int* out, int required);
extern "C" void func_002527B0(Str_00220318* out, void* table, int id);
extern "C" const char* func_001041B8(Str_00220318* s);
extern "C" void func_001040A8(Str_00220318* s, int flags);
extern "C" void func_001E7138(void* params, const char* name, const char* value);

bool func_00220318(void* params, Script_00220318* script)
{
    Str_00220318 name;
    int id;
    func_001E8A50(params, D_00371828, &id, 1);
    func_002527B0(&name, D_0038FC78->m_398, id);
    void* out = script->m_params;
    func_001E7138(out, D_0038F8A0, func_001041B8(&name));
    func_001040A8(&name, 2);
    return true;
}
