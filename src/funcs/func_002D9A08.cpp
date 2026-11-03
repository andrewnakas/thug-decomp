struct Req_002D9A08 {
    int m0;
    char m4[0x100];
    void (*m104)();
    unsigned int m108;
    unsigned int m10C;
    unsigned int m110;
    unsigned int m114;
};

struct X_002D9A08 {
    char pad0[0x78];
    int m78;
    char pad7C[0x20C - 0x7C];
    int m20C;
};

struct Mgr_002D9A08 {
    char pad0[8];
    void* m8;
    int mC;
    X_002D9A08* m10;
};

extern Mgr_002D9A08* D_00392068;
extern char D_00355078[][32];
extern char D_0037C8D8[];
extern char D_0037C8F0[];
extern "C" int func_001E7DE8(void* p, unsigned int key, int* out, int v);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_002D8E08();
extern "C" void func_002D5608(void* p, Req_002D9A08* r);

bool Cmd_002D9A08(void* params)
{
    Mgr_002D9A08* m = D_00392068;
    X_002D9A08* x = m->m10;
    int v = 0;
    if (func_001E7DE8(params, 0x7360C9EF, &v, 0))
        x->m78 = v;
    else
        x->m78 = x->m78 + 1;
    Req_002D9A08 req;
    func_003331D0(req.m4, D_0037C8D8, D_0037C8F0, D_00355078[x->m78]);
    req.m114 = 0x1C049404;
    req.m108 = 0x1C049404;
    req.m110 = 0x74E0CD35;
    req.m0 = 0x25800;
    if (x->m78 == 4)
        req.m10C = 0x7346E8E7;
    else
        req.m10C = 0xD932B07B;
    req.m104 = func_002D8E08;
    func_002D5608(m->m8, &req);
    x->m20C = 0;
    return true;
}
