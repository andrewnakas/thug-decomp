extern char D_00372B88[];
extern char D_00372BA0[];
extern char D_0038FCB8[];
extern "C" void* func_0022E058(void* self);
extern "C" unsigned int func_001F0D78(char* s);
extern "C" void* func_00202EF8(void* a, unsigned int name);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);

struct Mgr_0022E060 {
    float GetValue(int which);
};

float Mgr_0022E060::GetValue(int which)
{
    void* x = func_0022E058(this);
    void* params = 0;
    switch (which) {
    case 0:
        params = func_00202EF8(x, func_001F0D78(D_00372B88));
        break;
    case 1:
        params = func_00202EF8(x, func_001F0D78(D_00372BA0));
        break;
    }
    int v = 0;
    func_001E7E58(params, D_0038FCB8, &v, 0);
    return v;
}
