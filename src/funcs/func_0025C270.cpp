extern "C" bool func_001E8180(void* params, unsigned int name, void** out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);

struct Color_0025C270 {
    float r, g, b, a;
};

static inline void Set_0025C270(Color_0025C270* c, float r, float g, float b, float a)
{
    c->r = r;
    c->g = g;
    c->b = b;
    c->a = a;
}

Color_0025C270* GetColor_0025C270(Color_0025C270* ret, void* params, unsigned int name)
{
    void* s = 0;
    int use_default;
    if (func_001E8180(params, name, &s, 0) && (use_default = 1, func_001E7DE8(s, 0x5A96985D, &use_default, 0), !use_default)) {
        int r, g, b;
        func_001E7DE8(s, 0x7323E97C, &r, 1);
        func_001E7DE8(s, 0x0424D9EA, &g, 1);
        func_001E7DE8(s, 0x9D2D8850, &b, 1);
        Set_0025C270(ret, (float)r * 0.01f, (float)g * 0.01f, (float)b * 0.01f, 1.0f);
    } else {
        Set_0025C270(ret, 1.0f, 1.0f, 1.0f, 1.0f);
    }
    return ret;
}
