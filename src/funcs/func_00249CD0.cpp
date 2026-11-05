struct Obj_00249CD0;
extern char D_00390080[];
extern char D_00373C78[];
extern char D_00373C88[];
extern "C" void* func_00249FE0(Obj_00249CD0* self);
extern "C" bool func_001E7C80(void* params, unsigned int name, const char** out, int required);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_001E55F8(const char* name, int a);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" const char* func_00248950(Obj_00249CD0* self);

struct Obj_00249CD0 {
    unsigned int Fn(int idx);
};

unsigned int Obj_00249CD0::Fn(int idx)
{
    char a[128];
    char b[128];
    char c[128];
    const char* s;
    unsigned int r = 0;
    func_001E7C80(func_00249FE0(this), 0xBFECC45B, &s, 1);
    func_003331D0(a, D_00390080, s, idx);
    if (func_001E55F8(a, 0)) {
        r = func_001F0D78(a);
    } else if (idx) {
        const char* n = func_00248950(this);
        func_003331D0(b, D_00373C78, n, idx);
        if (func_001E55F8(b, 0)) {
            r = func_001F0D78(b);
        } else {
            func_003331D0(c, D_00373C88, idx);
            func_001E55F8(c, 0);
            r = func_001F0D78(c);
        }
    }
    return r;
}
