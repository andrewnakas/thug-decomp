struct Script_00228C88 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int assert_);
extern "C" void* func_001190D0(unsigned int size);
extern "C" void* func_001E6978(void* self);
extern "C" void func_00224A50(int id, void* s);
extern "C" void func_00224C60(void* s, int id, void* t);
extern "C" int func_001E9CF8(void* s, int max);
extern "C" void func_001E7200(void* s, unsigned int name, int value);
extern "C" int func_002277F0(int id);
extern "C" void func_001E78A8(void* s, unsigned int name, void* value);

bool func_00228C88(void* params, Script_00228C88* script)
{
    int id = 0;
    func_001E8398(params, 0x7321A8D6, &id, 0);
    void* a = func_001E6978(func_001190D0(8));
    func_00224A50(id, a);
    int sa = func_001E9CF8(a, 100000);
    void* b = func_001E6978(func_001190D0(8));
    func_00224C60(b, id, a);
    int sb = func_001E9CF8(b, 100000);
    func_001E7200(script->m_params, 0x172C1344, sa);
    func_001E7200(script->m_params, 0x96635475, sb);
    func_001E7200(script->m_params, 0x6AFD2F7F, 100);
    func_001E7200(script->m_params, 0xECBB8262, sb + 20 + sa);
    void* p = script->m_params;
    func_001E7200(p, 0xB35EB1D1, func_002277F0(id));
    func_001E78A8(script->m_params, 0x703E60CA, b);
    func_001E78A8(script->m_params, 0x671C9C00, a);
    return true;
}
