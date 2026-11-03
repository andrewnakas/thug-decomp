extern "C" bool func_001E8890(void* params, char* name, const char** out, int required);
extern "C" bool func_001E8870(void* params, unsigned int name, const char** out, int required);
extern "C" int func_001D0AA0(void* man);
extern "C" bool func_001D0708(void* man, const char* name, int a, int b, int c, int d, int e, void* params);
extern "C" bool func_001E53A0(unsigned int name, int a);
extern "C" bool func_001E8A50(void* params, char* name, int* out, int required);
extern "C" bool func_001E8A30(void* params, unsigned int name, int* out, int required);
extern "C" void func_001D09B0(void* man, const char* name, int value, int a);

extern void* D_0038DB38;
extern char D_0038F368[];
extern char D_0038F3A8[];

bool Cmd_LoadTexDict_0020E510(void* params, void* script)
{
    void* man = D_0038DB38;
    const char* name;
    if (!func_001E8890(params, D_0038F368, &name, 0)) {
        func_001E8870(params, 0, &name, 1);
    }
    if (!func_001D0708(man, name, 0, 0, func_001D0AA0(man), 0, 0, params) && !func_001E53A0(0x25DC7904, 0)) {
        return true;
    }
    int value = 0;
    if (func_001E8A50(params, D_0038F3A8, &value, 0) || func_001E8A30(params, 0, &value, 0)) {
        func_001D09B0(man, name, value, 0);
    }
    return true;
}
