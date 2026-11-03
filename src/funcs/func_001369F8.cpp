struct Rgba_001369F8 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_001369F8(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
    }
    Rgba_001369F8(const Rgba_001369F8& o) { v = o.v; }
};

struct Script_001369F8 {
    char pad[0x18];
    void* m18;
};

extern "C" Rgba_001369F8 func_00135E28();
extern "C" Rgba_001369F8 func_00135EC0(int which);
extern "C" void func_001E7200(void* s, unsigned int id, int v);

struct C_001369F8 {
    bool GetColors(Script_001369F8* script);
};

bool C_001369F8::GetColors(Script_001369F8* script)
{
    Rgba_001369F8 c(0, 0, 0, 0x80);
    c = func_00135E28();
    func_001E7200(script->m18, 0xED664897, c.v.r);
    func_001E7200(script->m18, 0x908BF647, c.v.g);
    func_001E7200(script->m18, 0x5F4FBA78, c.v.b);
    c = func_00135EC0(0);
    func_001E7200(script->m18, 0xE213AEB7, c.v.r);
    func_001E7200(script->m18, 0x6EF19631, c.v.g);
    func_001E7200(script->m18, 0x5EC44213, c.v.b);
    c = func_00135EC0(1);
    func_001E7200(script->m18, 0x95149E21, c.v.r);
    func_001E7200(script->m18, 0x19F6A6A7, c.v.g);
    func_001E7200(script->m18, 0x29C37285, c.v.b);
    return true;
}
