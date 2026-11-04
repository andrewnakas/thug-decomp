struct Script_00212DB0 {
    char pad0[0x18];
    void* m_params;
};

extern char D_00370768[];
extern char D_00370798[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_002304D0(unsigned int id, int a);
extern "C" void* func_00202EF8(void* table, unsigned int id);
extern "C" void func_001E73C8(void* params, const char* name, unsigned int value);

bool func_00212DB0(void* params, Script_00212DB0* script)
{
    void* out = script->m_params;
    unsigned int key;
    unsigned int table;
    unsigned int value;
    func_001E8398(params, 0, &key, 0);
    func_001E84E8(params, D_00370768, &table, 0);
    func_001E84E8(func_00202EF8(func_002304D0(table, 1), key), D_00370798, &value, 0);
    func_001E73C8(out, D_00370798, value);
    return true;
}
