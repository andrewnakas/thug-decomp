struct MemMgr_0025D5F0 {
    char m_pad[0xD8];
    void* m_D8;
    char m_padDC[0x110 - 0xDC];
    void* m_110;
    void* m_114;
};

struct Info_0025D5F0 {
    char m_pad[0x5C];
    char m_params[4];
};

extern MemMgr_0025D5F0* D_00388A70;
extern void* D_0038FC78;
extern char D_00390C10[];
extern char D_003757B8[];

extern "C" void func_0010EC50();
extern "C" const char* func_0025D560(const char* name);
extern "C" Info_0025D5F0* func_0022E3C8(void* mgr, int index);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);
extern "C" unsigned int func_00105520(const char* s);
extern "C" bool func_001DF9B0(unsigned int id);
extern "C" void func_0010A950(MemMgr_0025D5F0* mgr, void* heap);
extern "C" void func_0010A9B0(MemMgr_0025D5F0* mgr);
extern "C" int func_0010A6D0(MemMgr_0025D5F0* mgr);
extern "C" void func_0010B5F8(MemMgr_0025D5F0* mgr, int size);
extern "C" void* func_001046B0(int size);
extern "C" void* func_0010F360(void* p);
extern "C" void func_0010F5B0(void* p, const char* name, int a, int b);

struct Loader_0025D5F0 {
    int m_0;
    void* m_file;
    int m_loaded;
    char m_pad[0xB60 - 0xC];
    int m_B60;
    bool Load(const char* name, int flags);
};

extern "C" int func_0025C988(Loader_0025D5F0* self, int flags);

bool Loader_0025D5F0::Load(const char* name, int flags)
{
    bool async = false;
    if (flags < 0) async = false;
    func_0010EC50();
    const char* base = func_0025D560(name);
    Info_0025D5F0* info = func_0022E3C8(D_0038FC78, 0);
    int male = 0;
    func_001E7DE8(info->m_params, 0x3F813177, &male, 1);
    char buf[256];
    if (male)
        func_003331D0(buf, D_00390C10, base);
    else
        func_003331D0(buf, D_003757B8, base);
    if (!func_001DF9B0(func_00105520(buf)))
        m_B60 = 1;
    func_0010A950(D_00388A70, D_00388A70->m_D8);
    func_0010B5F8(D_00388A70, func_0010A6D0(D_00388A70) - 0x32000);
    func_0010A9B0(D_00388A70);
    func_0010A950(D_00388A70, D_00388A70->m_114);
    m_file = func_0010F360(func_001046B0(0xA20));
    func_0010A9B0(D_00388A70);
    func_0010A950(D_00388A70, D_00388A70->m_110);
    func_0010F5B0(m_file, name, flags, async);
    func_0010A9B0(D_00388A70);
    if (!async) {
        func_0025C988(this, flags);
        m_loaded = 1;
    }
    return true;
}
