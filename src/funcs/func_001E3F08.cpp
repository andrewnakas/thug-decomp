extern int D_0038881C;
extern char D_003646B8[];
extern "C" void func_0010BEB8(void* f);
extern "C" void* func_00112728(const char* name, int a, int mode);
extern "C" int func_001E3D30(const char* name);
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct File_001E3F08 {
    char m_name[0x100];
    int m100;
    void* m104;

    bool Open(const char* name, int mode);
};

bool File_001E3F08::Open(const char* name, int mode)
{
    if (m104) {
        func_0010BEB8(m104);
        m104 = 0;
    }
    m104 = func_00112728(name, 0, mode);
    if (!m104) return false;
    if (D_0038881C) {
        m100 = func_001E3D30(name);
        if (!m100) {
            func_0010BEB8(m104);
            m104 = 0;
            return false;
        }
    } else {
        func_003331D0(m_name, D_003646B8, name);
    }
    return m104 != 0;
}
