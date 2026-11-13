/* force: {"kind": "sched", "pass": 2, "block": 0, "clock": 3, "first": 7} */
/* blocked: sched2 dependents key in the prologue (deps 3 vs 2; forced = MATCH) (oracle) */
struct Vec_00120C28 {
    float x, y, z, w;
};

struct Array_00120C28 {
    char pad[0xC];
    unsigned int m_size;
};

extern void* D_00389520;
extern void* D_0038951C;
extern const float D_003874E8;
extern "C" void* func_0011FE68(void* p);
extern "C" int func_001E8618(void* s, unsigned int name);
extern "C" int func_001E7DE8(void* s, unsigned int name, int* out, int req);
extern "C" int func_001E88D8(void* s, unsigned int name, int* out, int req);
extern "C" Array_00120C28* func_001E55B8(void* s, int a);
extern "C" unsigned int func_001E9300(Array_00120C28* a, unsigned int i);
extern "C" void func_0011E0D0(void* mgr, unsigned int id, Vec_00120C28* c);
extern "C" void func_0011E110(void* mgr, unsigned int id, Vec_00120C28* c, int on);

extern "C" int func_00120C28(void* self, void* params)
{
    void* s = func_0011FE68(D_00389520);
    if (!s)
        return 0;
    if (!func_001E8618(s, 0x5A96985D))
        return 0;
    int off;
    func_001E7DE8(s, 0x5A96985D, &off, 0);
    if (off)
        return 0;
    int r;
    int g;
    int b;
    if (!func_001E88D8(s, 0x7323E97C, &r, 0))
        return 0;
    if (!func_001E88D8(s, 0x0424D9EA, &g, 0))
        return 0;
    if (!func_001E88D8(s, 0x9D2D8850, &b, 0))
        return 0;
    Array_00120C28* list = func_001E55B8(params, 0);
    if (!list)
        return 0;
    Vec_00120C28 c;
    c.w = 1.0f;

    for (unsigned int i = 0; i < list->m_size; i++) {
        unsigned int id = func_001E9300(list, i);
        func_0011E0D0(D_0038951C, id, &c);
        int on = 1;
        c.x = c.x * D_003874E8 * (float)r;
        c.y = c.y * D_003874E8 * (float)g;
        c.z = c.z * D_003874E8 * (float)b;
        Array_00120C28* excl = func_001E55B8((void*)0x20D9AC2F, 0);
        if (excl) {
            for (unsigned int j = 0; j < excl->m_size; j++) {
                if (func_001E9300(excl, j) == id)
                    on = 0;
            }
        }
        func_0011E110(D_0038951C, id, &c, on);
    }
    return 0;
}
