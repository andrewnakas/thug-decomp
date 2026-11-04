struct Script_00212C28 {
    char pad0[0x18];
    void* m_params;
};

extern char D_00370768[];
extern char D_00370778[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_002304D0(unsigned int id, int a);
extern "C" void* func_00202EF8(void* table, unsigned int id);
extern "C" bool func_001E7D18(void* params, const char* name, int* out, int required);
extern "C" void func_001E7138(void* params, const char* name, int value);

bool func_00212C28(void* params, Script_00212C28* script)
{
    void* out = script->m_params;
    unsigned int key;
    unsigned int table;
    int value;
    func_001E8398(params, 0, &key, 0);
    func_001E84E8(params, D_00370768, &table, 0);
    func_001E7D18(func_00202EF8(func_002304D0(table, 1), key), D_00370778, &value, 0);
    func_001E7138(out, D_00370778, value);
    return true;
}
