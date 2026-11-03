extern char D_00390C20[];
extern char D_00390C28[];
extern char D_00390C30[];
extern int D_0038DB38;

extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, void* src);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" float func_00135F10();
extern "C" float func_00135F20(int i);
extern "C" void func_00135EE8(float v);
extern "C" void func_00135EF8(int i, float v);
extern "C" void func_001364F8();
extern "C" bool func_001E8870(void* params, unsigned int name, char** out, int required);
extern "C" void* func_001D06C0(int mgr, char* name, int a);
extern "C" char* func_0025D560(char* name);
extern "C" char* func_00331A9C(char* dst, char* src);
extern "C" char* func_00331678(char* dst, char* src);
extern "C" void* func_001E5588(char* name, int a);
extern "C" bool func_001E8708(void* params, unsigned int name);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" void func_001F0210(unsigned int name, void* params, void* obj, int a, int b);
extern "C" int func_00105520(char* name);
extern "C" int func_001D0208(int mgr, char* name, int a, int b, int c, int d, int e, int f);
extern "C" unsigned int func_001F0D78(char* s);

struct Cut_0025E828 {
    char m_pad[0x3C];
    int m3C;
    unsigned int m40;
    int m44;
    int m48;
    int m4C;
    void* m50;
    float m54;
    float m58;
    float m5C;
    bool Load(void* params);
};

extern "C" void func_0025A9A8(Cut_0025E828* self, void* params);
extern "C" void func_0025ED38(Cut_0025E828* self);

bool Cut_0025E828::Load(void* params)
{
    bool ok = false;
    void* p = func_001E6978(func_001190D0(8));
    func_001E6AC8(p, params);
    func_0025A9A8(this, p);
    m54 = func_00135F10();
    m58 = func_00135F20(0);
    m5C = func_00135F20(1);
    func_00135EE8(0.0f);
    func_00135EF8(0, 0.0f);
    func_00135EF8(1, 0.0f);
    func_001364F8();
    char* name;
    func_001E8870(p, 0xA1DC81F9, &name, 1);
    int mgr = D_0038DB38;
    if (!func_001D06C0(mgr, name, 0)) {
        char* base = func_0025D560(name);
        char buf[256];
        func_00331A9C(buf, base);
        func_00331678(buf, D_00390C20);
        void* s = func_001E5588(buf, 0);
        if (s)
            func_001E6AC8(m50, s);
        int a = !func_001E8708(m50, 0xBAFA9F1C);
        int b = !func_001E8708(m50, 0xBAFA9F1C);
        if (func_001E8708(params, 0x7DDDE00E)) {
            a = 1;
            b = 1;
        }
        func_001E7200(m50, 0xCDF2B13E, a);
        ok = true;
        func_001E7200(m50, 0x9A4BDFF5, b);
        func_001E7200(m50, 0xED064302, 1);
        func_001E7200(m50, 0xBABF2DC9, 1);
        func_001E6AC8(m50, p);
        func_0025ED38(this);
        func_001F0210(0xE1CE826A, m50, 0, 0, 0);
        char buf1[256];
        func_00331A9C(buf1, base);
        func_00331678(buf1, D_00390C28);
        char buf2[256];
        func_00331A9C(buf2, base);
        func_00331678(buf2, D_00390C30);
        m44 = func_00105520(buf1);
        m4C = func_00105520(buf2);
        m3C = func_001D0208(mgr, name, 0, 0, 0, 0, 0, 0);
        m40 = func_001F0D78(name);
    }
    if (p)
        func_001E6AE8(p, 3);
    return ok;
}
