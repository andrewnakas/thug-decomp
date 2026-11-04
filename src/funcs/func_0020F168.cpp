extern char D_0038F3E0[];
extern void* D_0038E0A0;

extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" void func_001DD620(void* mgr, float value, int id, bool flag);

bool func_0020F168(void* params)
{
    float value = 0.0f;
    int id = 0;
    func_001E7EB0(params, 0, &value, 0);
    if (value > 100.0f)
        value = 100.0f;
    func_001E7DE8(params, 0x6835B854, &id, 0);
    float v = value;
    int i = id;
    void* mgr = D_0038E0A0;
    func_001DD620(mgr, v, i, func_001E87B8(params, D_0038F3E0));
    return true;
}
