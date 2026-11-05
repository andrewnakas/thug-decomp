extern char D_0037AD98[];
extern "C" bool func_001E88F8(void* params, const char* name, int* out, int required);
extern "C" void* func_002CC830();
extern "C" void func_002CC668(void* p, int v, void* script);

bool func_002CB650(void* params, void* script)
{
    int v;
    func_001E88F8(params, D_0037AD98, &v, 1);
    func_002CC668(func_002CC830(), v, script);
    return true;
}
