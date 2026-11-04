extern "C" int func_003331D0(char* buf, char* fmt, int a);
extern "C" void* func_0010EC78(char* name, int a, int b);
extern "C" int func_0010E558(void* f);
extern "C" void func_0010E698(void* f, void* dst, int a, int n);
extern "C" void func_0010ECF8(void* f);
extern char D_00364438[];

struct Fam_001E1268 {
    int m_id;
    int m_size;
    char pad8[8];
    char m_data[0x1000];
    bool Load(int id);
};

bool Fam_001E1268::Load(int id)
{
    char buf[256];
    func_003331D0(buf, D_00364438, id);
    void* f = func_0010EC78(buf, 1, 100);
    if (f) {
        int n = func_0010E558(f);
        m_size = n;
        if (n >= 0x1000) {
            func_0010ECF8(f);
            return false;
        }
        func_0010E698(f, m_data, 1, n);
        func_0010ECF8(f);
        m_id = id;
        return true;
    }
    return false;
}
