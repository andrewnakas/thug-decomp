extern char D_0038F368[];
extern char D_0038F708[];
extern void* D_00388A70;
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void func_0010BC98(void* pool, unsigned int id, int v, char* name);

bool Cmd_00219120(void* params, void* script)
{
    char* name;
    int v;
    func_001E8890(params, D_0038F368, &name, 1);
    func_001E88F8(params, D_0038F708, &v, 1);
    func_0010BC98(D_00388A70, func_001F0D78(name), v, name);
    return true;
}
