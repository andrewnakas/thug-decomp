extern char D_0038F8E0[];
extern char D_0038F908[];
extern char D_00371A20[];
extern char D_00371A38[];
extern char D_00371A48[];
extern char D_00371A60[];

struct Script_00222918 {
    char pad[0x18];
    void* m_params;
};

extern "C" bool func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E81F0(void* params, char* name, void** out, int required);
extern "C" void func_001E7D70(void* params, unsigned int key, char** out, int required);
extern "C" void func_001E7C80(void* params, unsigned int key, char** out, int required);
extern "C" void func_001E7138(void* params, char* name, char* value);
extern "C" void func_001E73C8(void* params, char* name, unsigned int value);
extern "C" bool func_001E82B8(void* params, char* name, void** out, int required);
extern "C" unsigned int func_001E9300(void* a, int b);
extern "C" void* func_001E55B8(unsigned int key, int a);
extern "C" void* func_001E9378(void* a, int b);

bool func_00222918(void* params, Script_00222918* script)
{
    unsigned int name;
    func_001E84E8(params, D_0038F8E0, &name, 1);
    void* s = func_001E5548(name, 1);
    if (s) {
    void* p;
    func_001E81F0(s, D_0038F908, &p, 1);
    char* text;
    func_001E7D70(p, 0xA1DC81F9, &text, 1);
    func_001E7138(script->m_params, D_00371A20, text);
    unsigned int extra = 0;
    if (!func_001E84E8(p, D_00371A38, &extra, 0)) {
        void* arr;
        if (func_001E82B8(p, D_00371A38, &arr, 0))
            extra = func_001E9300(arr, 0);
    }
    if (extra) {
    void* p2;
    func_001E81F0(func_001E9378(func_001E55B8(extra, 1), 0), D_0038F908, &p2, 1);
    char* text2;
    func_001E7C80(p2, 0xA1DC81F9, &text2, 1);
    func_001E7138(script->m_params, D_00371A48, text2);
    func_001E73C8(script->m_params, D_00371A60, extra);
    }
    return true;
    }
    return false;
}
