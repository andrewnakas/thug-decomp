extern char D_00363E18[];

extern "C" void func_00229340(const char* path, int a);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" int func_00331BB8(const char* s);
extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" void* func_001E55F8(const char* name, int a);

struct Base_001D1D38 {
    char m_pad[0x20];
};

class VBase_001D1D38 : public Base_001D1D38 {
public:
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
    virtual void SetScript(void* script);
};

class Obj_001D1D38 : public VBase_001D1D38 {
public:
    unsigned int m24;
    int Load(const char* path);
};

int Obj_001D1D38::Load(const char* path)
{
    func_00229340(path, 1);
    m24 = func_001F0D78(path);
    const char* p = path + (func_00331BB8(path) - 1);
    while (*p != '\\' && *p != '/')
        p--;
    char buf[128];
    func_00331A9C(buf, p + 1);
    func_003331D0(buf + (func_00331BB8(buf) - 3), D_00363E18);
    void* script = func_001E55F8(buf, 0);
    SetScript(script);
    return 0;
}
