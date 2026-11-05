struct Item_0020DE10 {
    char pad0[0x1C];
    int m_1C;
};

struct Mgr_0020DE10 {
    char pad0[0x28];
    Item_0020DE10* m_items[1];
};

struct Info_0020DE10 {
    char pad0[0x254];
    float m_254;
    float m_258;
    float m_25C;
    float m_260;
    char pad264[0x1C];
};

struct Script_0020DE10 {
    char pad0[0x18];
    void* m_params;
};

extern Mgr_0020DE10* D_00390828;

extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0026F090(Info_0020DE10* info);
extern "C" void func_0026F1C0(Info_0020DE10* info, int id);
extern "C" void func_001E72B0(void* params, unsigned int name, float value);

bool func_0020DE10(void* params, Script_0020DE10* script)
{
    Info_0020DE10 info;
    int index = 0;
    Mgr_0020DE10* mgr = D_00390828;
    func_001E7DE8(params, 0xB30D9965, &index, 0);
    Item_0020DE10* item = mgr->m_items[index];
    func_0026F090(&info);
    func_0026F1C0(&info, item->m_1C);
    func_001E72B0(script->m_params, 0x303067F1, info.m_25C);
    func_001E72B0(script->m_params, 0x47375767, info.m_260);
    func_001E72B0(script->m_params, 0x694DF774, info.m_254);
    func_001E72B0(script->m_params, 0x1E4AC7E2, info.m_258);
    return true;
}
