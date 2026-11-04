extern char D_00389F70[];
extern char D_00389F78[];
extern char D_00389F80[];
extern "C" void func_001E7E58(void* params, const void* name, void* out, int b);

struct Bytes138100 {
    unsigned char r, g, b, a;
};

static inline void Set(Bytes138100& c, unsigned char ar, int ag, int ab, int aa) { c.r = ar; c.g = ag; c.b = ab; c.a = aa; }

extern "C" void func_00138100(const Bytes138100& p);

int func_00138300(void* params)
{
    int r, g, b;
    func_001E7E58(params, D_00389F70, &r, 0);
    func_001E7E58(params, D_00389F78, &g, 0);
    func_001E7E58(params, D_00389F80, &b, 0);
    Bytes138100 c;
    Set(c, r, g, b, 0x80);
    Bytes138100 t = c;
    func_00138100(t);
    return 1;
}
