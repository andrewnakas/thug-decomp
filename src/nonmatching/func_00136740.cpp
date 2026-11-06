/* fuzzy: 97.4 */
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern char D_00389E58[];
extern char D_00389E60[];
extern char D_00389E68[];

struct Rgba_00136740 {
    unsigned char r, g, b, a;
    Rgba_00136740(unsigned char ar, int ag, int ab, int aa)
    {
        r = ar;
        g = ag;
        b = ab;
        a = aa;
    }
    Rgba_00136740(const Rgba_00136740& o) { *this = o; }
};

extern "C" void func_00135DF0(Rgba_00136740 c);

extern "C" void func_00136740(void* params)
{
    int r, g, b;
    func_001E7E58(params, D_00389E58, &r, 0);
    func_001E7E58(params, D_00389E60, &g, 0);
    func_001E7E58(params, D_00389E68, &b, 0);
    Rgba_00136740 c(r, g, b, 0x80);
    func_00135DF0(c);
}
