extern char D_0038F4B8[];
extern char D_0038F4C0[];
extern char D_0038F350[];
extern char D_0038F348[];

struct Color_00212910 {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    Color_00212910(unsigned char r_, int g_, int b_, int a_) : r(r_), g(g_), b(b_), a(a_) {}
};

extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_00144120(Color_00212910* c);

static inline void SetColor_00212910(Color_00212910 c)
{
    func_00144120(&c);
}

bool Cmd_00212910(void* params, void* script)
{
    int r = 0xFF;
    int g = 0xFF;
    int b = 0xFF;
    int a = 0x80;
    func_001E7E58(params, D_0038F4B8, &r, 0);
    func_001E7E58(params, D_0038F4C0, &g, 0);
    func_001E7E58(params, D_0038F350, &b, 0);
    func_001E7E58(params, D_0038F348, &a, 0);
    Color_00212910 c(r, g, b, a);
    SetColor_00212910(c);
    return true;
}
