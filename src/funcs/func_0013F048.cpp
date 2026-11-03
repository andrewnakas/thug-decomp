struct H_0013F048 {
    char m_pad0[0xD8];
    void* m_D8;
};

struct V_0013F048 {
    unsigned char r, g, b, a;
    char m_pad4[0x1C];
    int m_20;
    char m_pad24[0x1C];
};

struct O_0013F048 {
    char m_pad0[0x40];
};
extern "C" void func_001228A8(O_0013F048* o, int id);
extern "C" void func_00122060(O_0013F048* o);

extern H_0013F048* D_00388A70;
extern void* D_00393EF4;
extern "C" void func_0010A950(H_0013F048* heap, void* ctx);
extern "C" void func_0010A9B0(H_0013F048* heap);
extern "C" int func_00123430(void* src);
extern "C" int func_00123438(void* src);
extern "C" int func_00123550(void* src);
extern "C" V_0013F048 func_00123440(void* src);
extern "C" void* func_00139008(void* mgr, int a, int b, int name, int c, int d, int e);
extern "C" void* func_00138F58(void* mgr, int a, int b, int c, int d);
extern "C" int func_001E5548(int name, int a);
extern "C" void func_001220E0(void* p);
extern "C" void func_001220E8(void* p, V_0013F048 v, int a, int b, V_0013F048* c);
extern "C" int func_00138918(void* p);
extern "C" bool func_0013DC60(void* self, int key, const char* a, int id);
extern "C" void func_001390E0(void* mgr, void* p);

class C_0013F048 {
public:
    bool Show(void* src, const char* text, int key);
};

bool C_0013F048::Show(void* src, const char* text, int key)
{
    func_0010A950(D_00388A70, D_00388A70->m_D8);
    int x = func_00123430(src);
    void* a = func_00139008(D_00393EF4, x, func_00123438(src), 0xB00B0DC0, 1, 1, 0);
    void* b = func_00138F58(D_00393EF4, func_00123550(src), 1, 1, 1);
    func_0010A9B0(D_00388A70);
    O_0013F048 o;
    func_001228A8(&o, func_001E5548(0xA435752C, 1));
    func_00122060(&o);
    func_001220E0(b);
    V_0013F048 c = func_00123440(src);
    c.r = 0x80;
    c.g = 0x80;
    c.b = 0x80;
    c.a = 0x80;
    int m = c.m_20;
    func_001220E8(a, func_00123440(src), m, 0, &c);
    bool r = func_0013DC60(this, key, text, func_00138918(a));
    func_001390E0(D_00393EF4, a);
    func_001390E0(D_00393EF4, b);
    return r;
}
