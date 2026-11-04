extern "C" void func_0010BFC0(const char* name);
extern "C" void func_0010BFC8();
extern "C" void* func_001321E0(const char* name, int c, bool a, int b);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" void func_00104418(char* s);
extern "C" char* func_003364D8(const char* s, const char* sub);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_0013F2B8(void* p, const char* name);
extern char D_0038DD50[];

struct Desc_001D1838 {
    int a;
    int b;
    int c;
};

struct Obj_001D1838 {
    char pad[0x20];
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
    virtual void V10(void* p);
    int Load(const char* name, int u0, int u1, Desc_001D1838* desc, void* params);
};

int Obj_001D1838::Load(const char* name, int u0, int u1, Desc_001D1838* desc, void* params)
{
    func_0010BFC0(name);
    Desc_001D1838 d;
    d.a = 0;
    d.b = 0;
    d.c = 0;
    if (desc) d = *desc;
    void* p = func_001321E0(name, d.c, d.a != 0, d.b);
    if (!p) return -1;
    V10(p);
    char buf[0x80];
    func_00331A9C(buf, name);
    func_00104418(buf);
    if (func_003364D8(buf, D_0038DD50)) {
        int v = 0;
        if (params) func_001E7DE8(params, 0xBF29BC0, &v, 0);
        if (!v) func_0013F2B8(p, name);
    }
    func_0010BFC8();
    return 0;
}
