struct Item_0021D2B0 {
    int m_0;
    char m_4[0x58];
    char m_5C[4];
};

extern void* D_0038FC78;
extern char D_003716C8[];
extern char D_0038F830[];

extern "C" Item_0021D2B0* func_0022E368(void* mgr, void* params);
extern "C" bool func_001E8A10(void* params, const char* name, int* out, int required);
extern "C" void func_0011FAB8(void* table, int key, int a);
extern "C" void func_001E6AC8(void* s, int src);
extern "C" void func_00262458(Item_0021D2B0* item, int a);

bool func_0021D2B0(void* params)
{
    Item_0021D2B0* item = func_0022E368(D_0038FC78, params);
    int key;
    func_001E8A10(params, D_003716C8, &key, 1);
    func_0011FAB8(item->m_4, key, 1);
    int src;
    func_001E8A10(params, D_0038F830, &src, 1);
    func_001E6AC8(item->m_5C, src);
    func_00262458(item, 1);
    return true;
}
