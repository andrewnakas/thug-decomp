struct Item_0023EC68 {
    char pad[0x18];
    void* m_18;
};

struct Script_0023EC68 {
    char pad[0x18];
    void* m_params;
};

struct Mgr_0023EC68 {
    void Call(int id, void* params, Script_0023EC68* script);
};

extern "C" Item_0023EC68* func_0023BAD8(Mgr_0023EC68* self, int id, int create);
extern "C" unsigned int func_00249CD0(void* a, void* params);
extern "C" void func_001E6B90(void* params, unsigned int name);
extern "C" void func_001E7360(void* params, unsigned int name, unsigned int value);

void Mgr_0023EC68::Call(int id, void* params, Script_0023EC68* script)
{
    unsigned int r = func_00249CD0(func_0023BAD8(this, id, 1)->m_18, params);
    func_001E6B90(script->m_params, 0x18653764);
    if (r) {
        func_001E7360(script->m_params, 0x18653764, r);
    }
}
