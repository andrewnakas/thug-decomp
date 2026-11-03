extern char D_0038F590[];
extern char D_0038F558[];
extern char D_00370E28[];
extern char D_00370E38[];

extern "C" bool func_001E84E8(void* params, const char* name, int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" void* func_00141250(int id);
extern "C" void func_00140360(void* p, int a, void* b);
extern "C" void func_00140400(void* p, int a, void* b);

bool Cmd_00218168(void* params, void* script)
{
    int id = 0;
    func_001E84E8(params, D_0038F590, &id, 0);
    void* data = 0;
    func_001E81F0(params, D_0038F558, &data, 0);
    void* obj = func_00141250(id);
    int a = 0;
    if (func_001E84E8(params, D_00370E28, &a, 0))
        func_00140360(obj, a, data);
    int b = 0;
    if (func_001E84E8(params, D_00370E38, &b, 0))
        func_00140400(obj, b, data);
    return true;
}
