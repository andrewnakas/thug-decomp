extern char D_0038F3F8[];
extern char D_0038F400[];
extern char D_003702F0[];
extern float D_00387CAC;

extern "C" bool func_001E8938(void* params, const char* name, float* out, int required);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" void* func_00131E48();
extern "C" void* func_00131E88();
extern "C" void func_0020F398(void* s, float a, float b, unsigned int id);

bool func_0020FBA0(void* params)
{
    float vol = 0.0f;
    func_001E8938(params, D_0038F3F8, &vol, 1);
    float pan = 0.0f;
    func_001E7F50(params, D_0038F400, &pan, 0);
    pan = (100.0f - pan) * D_00387CAC;
    unsigned int id = 0;
    func_001E84E8(params, D_003702F0, &id, 0);
    void* s = func_00131E48();
    if (s)
        func_0020F398(s, vol, pan, id);
    s = func_00131E88();
    if (s)
        func_0020F398(s, vol, pan, id);
    return true;
}
