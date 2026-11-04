extern char D_0038F6F0[];
extern char D_0038F6F8[];
extern char D_0038F3F8[];
extern char D_00370ED8[];
extern char D_00370EE8[];
extern char D_0038F700[];
extern float D_00387CC8;

struct Script_00218DF8 {
    char pad0[0x18];
    void* m_params;
};

extern "C" bool func_001E8938(void* params, const char* name, float* out, int required);
extern "C" bool func_001E87B8(void* params, const char* name);
extern "C" float func_003413F0(float x);
extern "C" void func_001E7318(void* params, const char* name, float value);

bool func_00218DF8(void* params, Script_00218DF8* script)
{
    float lo;
    float hi;
    float value;
    func_001E8938(params, D_0038F6F0, &lo, 1);
    func_001E8938(params, D_0038F6F8, &hi, 1);
    func_001E8938(params, D_0038F3F8, &value, 1);
    float t = (value - lo) / (hi - lo);
    if (func_001E87B8(params, D_00370ED8)) {
        t = func_003413F0(t) * D_00387CC8;
        if (func_001E87B8(params, D_00370EE8))
            t = 2048.0f - t;
    }
    func_001E7318(script->m_params, D_0038F700, t);
    return true;
}
