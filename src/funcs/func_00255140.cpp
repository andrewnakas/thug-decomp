struct Ref_00255140;

extern "C" void func_00183CB8(void* p, Ref_00255140* ref);
extern "C" void func_00183C98(void* p, Ref_00255140* ref);

struct Ref_00255140 {
    void* m_p;
    void Set(void* p)
    {
        if (m_p) {
            func_00183CB8(m_p, this);
            m_p = 0;
        }
        m_p = p;
        if (p)
            func_00183C98(p, this);
    }
};

struct Obj_00255140 {
    char pad0[0xBC];
    Ref_00255140 m_target;
};

struct Args_00255140 {
    const char* m_name;
    char pad4[0x18];
    void* m_target;
};

extern char D_00375388[];

extern "C" int func_003331D0(char* buf, const char* fmt, const char* name);
extern "C" void func_00229340(const char* name, int a);
extern "C" Obj_00255140* func_001F0938(const char* name, int a, int b, int c, int d, int e, int f, int g, int h, int i);

bool func_00255140(Args_00255140* args)
{
    const char* name = args->m_name;
    void* target = args->m_target;
    char buf[0x100];
    func_003331D0(buf, D_00375388, name);
    func_00229340(buf, 0);
    Obj_00255140* o = func_001F0938(name, 0, 0, 0, -1, 0, 0, 0, 0, 0);
    o->m_target.Set(target);
    return true;
}
