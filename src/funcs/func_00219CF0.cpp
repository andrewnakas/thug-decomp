extern char D_0038F728[];
extern "C" bool func_001E8890(void* params, char* name, int* out, int required);
extern "C" void func_00106248(int v);

extern "C" bool func_00219CF0(void* params, void* script)
{
    int v;
    func_001E8890(params, D_0038F728, &v, 1);
    func_00106248(v);
    return true;
}
