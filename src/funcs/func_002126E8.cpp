extern char D_0038F4D0[];
extern char D_0038F4D8[];
extern char D_00370738[];

extern "C" int func_001E7F50(void* params, const char* name, float* out, int req);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" void func_00135EE8(float t);
extern "C" void func_00135EF8(int i, float t);

bool Cmd_002126E8(void* params, void* script)
{
    float t;
    int i = 0;
    t = 0.0f;
    if (func_001E7F50(params, D_0038F4D0, &t, 0)) {
        if (func_001E87B8(params, D_0038F4D8)) {
            func_00135EE8(t);
        } else {
            func_001E7E58(params, D_00370738, &i, 0);
            func_00135EF8(i, t);
        }
    }
    return true;
}
