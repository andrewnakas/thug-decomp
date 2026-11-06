extern char D_00370910[];
extern char D_0038F570[];
extern void* D_00389044;
extern "C" bool func_001E8890(void* params, char* name, char** out, int required);
extern "C" void func_001822F0(void* obj, char* s);

bool Cmd_00213910(void* params, void* script)
{
    char* s;
    if (!func_001E8890(params, D_00370910, &s, 0))
        s = D_0038F570;
    func_001822F0(D_00389044, s);
    return true;
}
