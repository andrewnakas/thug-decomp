extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int name, void** out, int req);
extern "C" int func_001E88B0(void* params, unsigned int name, const char** out, int req);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_00336228(const char* a, const char* b);

struct C_001AF390 {
    int m_pad[667];
    void* mA6C;
    int IsNamed(void* p, const char* name);
};

int C_001AF390::IsNamed(void* p, const char* name)
{
    unsigned int n = 0;
    if (func_001E8398(p, 0xA92A2280, &n, 0)) {
        unsigned int q = 0;
        func_001E8398(mA6C, n, &q, 0);
        if (q) {
            p = func_001E5548(q, 0);
            if (!p) return 0;
        }
    }
    void* w = 0;
    func_001E8180(p, 0x7031F10C, &w, 0);
    if (w) {
        const char* s = 0;
        func_001E88B0(w, 0xA1DC81F9, &s, 0);
        if (!s) return 0;
        int r = func_00336228(s, name);
        if (!r) return 1;
    }
    return 0;
}
