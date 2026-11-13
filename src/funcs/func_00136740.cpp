extern char D_00389E58[];
extern char D_00389E60[];
extern char D_00389E68[];
extern "C" void func_001E7E58(void* params, const void* name, void* out, int b);

struct Rgba_00136740 {
    unsigned char r, g, b, a;
};

static inline void Set(Rgba_00136740& c, unsigned char ar, int ag, int ab, int aa) { c.r = ar; c.g = ag; c.b = ab; c.a = aa; }

/* game: func_00135DF0 ends "jal func_0014ABD0" with v0 untouched, and func_0014ABD0 returns 1 (addiu v0,zero,1) */
extern "C" bool func_00135DF0(const Rgba_00136740& c);

/* Script command (referenced from a data table); returns func_00135DF0's result, game leaves v0 untouched after that jal. */
extern "C" bool func_00136740(void* params)
{
    int r, g, b;
    func_001E7E58(params, D_00389E58, &r, 0);
    func_001E7E58(params, D_00389E60, &g, 0);
    func_001E7E58(params, D_00389E68, &b, 0);
    Rgba_00136740 c;
    Set(c, r, g, b, 0x80);
    Rgba_00136740 t = c;
    return func_00135DF0(t);
}
