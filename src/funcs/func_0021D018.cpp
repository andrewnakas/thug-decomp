extern void* D_0038FC78;

struct Script_0021D018 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void* func_0022E050(void* game);
extern "C" int func_00262828(void* p);
extern "C" char* func_00262860(void* p, int i);
extern "C" void func_001E6AC8(void* params, void* src);

bool Cmd_0021D018(void* params, Script_0021D018* script)
{
    unsigned int name;
    func_001E8398(params, 0xA1DC81F9, &name, 1);
    void* list = func_0022E050(D_0038FC78);
    int n = func_00262828(list);
    for (int i = 0; i < n; i++) {
        void* p = func_00262860(list, i) + 0x5C;
        unsigned int k;
        func_001E8398(p, 0xA1DC81F9, &k, 1);
        if (k == name) {
            func_001E6AC8(script->m_params, p);
            return true;
        }
    }
    return false;
}
