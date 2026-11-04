struct Color_002B70A8 {
    unsigned char r, g, b, a;
};

extern "C" void* func_001317D0(void* p);
extern "C" void* func_00134F18(void* p);
extern "C" void func_0013C438(void* p, Color_002B70A8* c);
extern "C" void func_0013C478(void* p);

struct Obj_002B70A8 {
    void* m0;
    void SetHighlight(int on, int alt);
};

void Obj_002B70A8::SetHighlight(int on, int alt)
{
    void* p = func_001317D0(m0);
    if (!p)
        return;
    void* q = func_00134F18(p);
    if (!q)
        return;
    if (on) {
        Color_002B70A8 c;
        if (alt) {
            c.g = 100;
            c.r = 0xA0;
            c.b = 0xA0;
            c.a = 0;
            func_0013C438(q, &c);
        } else {
            c.r = 0xA0;
            c.g = 100;
            c.b = 100;
            c.a = 0;
            func_0013C438(q, &c);
        }
    } else {
        func_0013C478(q);
    }
}
