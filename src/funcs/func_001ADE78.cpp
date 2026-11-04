extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E8248(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, unsigned int* out, int req);
extern "C" void* func_001E5548(unsigned int id, int flags);

struct C_001ADE78 {
    int m_pad[667];
    void* mA6C;
    int HasTarget(void* p);
};

int C_001ADE78::HasTarget(void* p)
{
    unsigned int a = 0;
    if (func_001E8398(p, 0xA6D2D890, &a, 0)) return 1;
    if (func_001E8398(p, 0x22E168C1, &a, 0)) return 1;
    int b = 0;
    if (func_001E8248(p, 0x689FE07C, &b, 0)) return 1;
    unsigned int n = 0;
    if (func_001E8398(p, 0xA92A2280, &n, 0)) {
        unsigned int q = 0;
        func_001E8398(mA6C, n, &q, 0);
        if (q) {
            if (func_001E5548(q, 0)) return 1;
        } else {
            unsigned int r = 0;
            int ok = func_001E7DE8(mA6C, n, &r, 0);
            if (ok) return 1;
        }
    }
    return 0;
}
