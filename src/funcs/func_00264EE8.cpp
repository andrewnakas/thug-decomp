struct Color_00264EE8 {
    unsigned char r, g, b, a;
    Color_00264EE8() {}
    Color_00264EE8(const Color_00264EE8& o) { r = o.r; g = o.g; b = o.b; a = o.a; }
};

extern char D_00375F08[];
extern "C" void* func_001317D0(void* p);
extern "C" void* func_001E55F8(const char* name, int a);
extern "C" void* func_001E93A0(void* arr, int i);
extern "C" int func_001E9270(void* arr, int i);
extern "C" Color_00264EE8 func_00134F88(void* m);
extern "C" void func_00134F60(void* m);

struct Obj_00264EE8 {
    char pad[0x18];
    void* m18;
    bool Apply(int idx);
};

bool Obj_00264EE8::Apply(int idx)
{
    void* m = func_001317D0(m18);
    void* arr = func_001E93A0(func_001E55F8(D_00375F08, 0), idx);
    Color_00264EE8 c;
    c.r = func_001E9270(arr, 0);
    c.g = func_001E9270(arr, 1);
    c.b = func_001E9270(arr, 2);
    c.a = 0x80;
    Color_00264EE8 cur = func_00134F88(m);
    if (cur.r == c.r && cur.g == c.g && cur.b == c.b) func_00134F60(m);
    return true;
}
