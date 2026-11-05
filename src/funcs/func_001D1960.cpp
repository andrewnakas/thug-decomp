struct Tex_001D1960;

struct Desc_001D1960 {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
};

extern char D_00363CE0[];

extern "C" int func_003331D0(char* buf, const char* fmt);
extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" Tex_001D1960* func_00132348(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j);

class Base_001D1960 {
public:
    char pad0[0x20];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void Add(Tex_001D1960* t);

    int Create(const Desc_001D1960* d);
};

int Base_001D1960::Create(const Desc_001D1960* d)
{
    char buf[0x100];
    func_003331D0(buf, D_00363CE0);
    func_0010BFC0(buf);
    Tex_001D1960* t = func_00132348(d->m_0, d->m_4, d->m_8, d->m_14, d->m_18, d->m_C, d->m_10, d->m_1C, d->m_20, d->m_24);
    if (!t)
        return -1;
    Add(t);
    func_0010BFC8();
    return 0;
}
