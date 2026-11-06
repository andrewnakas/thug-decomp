/* fuzzy: 87.4 */
struct Heap_0025D5F0 {
    char pad[0xD8];
    int mD8;
    char padDC[0x34];
    int m110;
    int m114;
};

struct Sk_0025D5F0 {
    char pad[0x5C];
    char m5C[4];
};

extern Heap_0025D5F0* D_00388A70;
extern void* D_0038FC78;
extern char D_00390C10[];
extern char D_003757B8[];
extern "C" int func_0010EC50();
extern "C" char* func_0025D560(const char* path);
extern "C" Sk_0025D5F0* func_0022E3C8(void* mgr, int id);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_00105520(void* p);
extern "C" int func_001DF9B0(void* p);
extern "C" void func_0010A950(void* p, int v);
extern "C" void func_0010A9B0(void* p);
extern "C" int func_0010A6D0(void* p);
extern "C" void func_0010B5F8(void* p, int v);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0010F360(void* p);
extern "C" void func_0010F5B0(void* p, const char* name, int a, int b);
extern "C" void func_0025C988(void* self, int a);

struct Obj_0025D5F0 {
    int m0;
    void* m4;
    int m8;
    char padC[0xB54];
    int mB60;
    bool Fn(const char* name, int a);
};

bool Obj_0025D5F0::Fn(const char* name, int a)
{
    int async = 0;
    func_0010EC50();
    char* base = func_0025D560(name);
    int v = 0;
    char buf[0x100];
    func_001E7DE8(func_0022E3C8(D_0038FC78, 0)->m5C, 0x3F813177, &v, 1);
    if (v) func_003331D0(buf, D_00390C10, base);
    else func_003331D0(buf, D_003757B8, base);
    if (!func_001DF9B0(func_00105520(buf))) mB60 = 1;
    func_0010A950(D_00388A70, D_00388A70->mD8);
    func_0010B5F8(D_00388A70, func_0010A6D0(D_00388A70) + 0xFFFCE000);
    func_0010A9B0(D_00388A70);
    func_0010A950(D_00388A70, D_00388A70->m114);
    m4 = func_0010F360(func_001046B0(0xA20));
    func_0010A9B0(D_00388A70);
    func_0010A950(D_00388A70, D_00388A70->m110);
    func_0010F5B0(m4, name, a, async);
    func_0010A9B0(D_00388A70);
    if (!async) {
        func_0025C988(this, a);
        m8 = 1;
    }
    return true;
}
