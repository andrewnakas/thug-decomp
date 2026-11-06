extern char D_0038F368[];
extern void* D_00388A70;
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" char* func_001F0D78(char* s);
extern "C" int func_0010BD68(void* heap, char* s, int a);

extern "C" int func_00219190(void* params)
{
    char* name;
    func_001E8890(params, D_0038F368, &name, 1);
    void* heap = D_00388A70;
    return func_0010BD68(heap, func_001F0D78(name), 0);
}
