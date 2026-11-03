extern char D_0038F4F8[];
extern char D_0038F500[];
extern char D_0038F508[];
extern char D_0038F510[];
extern char D_0038F518[];
extern char D_0038F520[];
extern char D_0038F528[];
extern char D_0038F530[];
extern char D_0038F538[];

extern "C" bool func_001E84E8(void* params, const char* name, int* out, int required);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" void* func_001317D0(int id);
extern "C" void func_00135508(void* obj, float a, float b, float c, float d, float e, float f, float g, float h);

bool Cmd_002129E0(void* params, void* script)
{
    int id;
    float a, b, c, d, e, f, g, h;
    func_001E84E8(params, D_0038F4F8, &id, 0);
    void* obj = func_001317D0(id);
    func_001E7F50(params, D_0038F500, &a, 0);
    func_001E7F50(params, D_0038F508, &b, 0);
    func_001E7F50(params, D_0038F510, &c, 0);
    func_001E7F50(params, D_0038F518, &d, 0);
    func_001E7F50(params, D_0038F520, &e, 0);
    func_001E7F50(params, D_0038F528, &f, 0);
    func_001E7F50(params, D_0038F530, &g, 0);
    func_001E7F50(params, D_0038F538, &h, 0);
    func_00135508(obj, a, b, c, d, e, f, g, h);
    return true;
}
