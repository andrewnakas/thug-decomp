struct Item_00221730 {
    char pad0[0x5C];
    char m_params[4];
};

extern void* D_0038FC78;
extern char D_003718C0[];

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0022E050(void* mgr);
extern "C" Item_00221730* func_002629B8(void* mgr, unsigned int id);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_001E7268(void* params, const char* name, int value);

bool func_00221730(void* params)
{
    unsigned int id;
    func_001E8398(params, 0xA1DC81F9, &id, 1);
    void* p = func_002629B8(func_0022E050(D_0038FC78), id)->m_params;
    int value = 1;
    func_001E7E58(p, D_003718C0, &value, 1);
    if (value)
        func_001E7268(p, D_003718C0, 0);
    return true;
}
