struct Rpc_002DB820 {
    char pad0[0x24];
    int m24;
};

extern char D_0037CB30[];
extern char D_0037CB40[];
extern char D_0037CB60[];
extern Rpc_002DB820 D_00453B00;
extern int D_00392EF0;

extern "C" int func_0031FE48(char* name);
extern "C" int func_00332FB0(const char* fmt, ...);
extern "C" int func_0031DBA0(Rpc_002DB820* c, unsigned int id, int mode);

static inline bool NotBound_002DB820()
{
    if (func_0031DBA0(&D_00453B00, 0x75499128, 0) < 0)
        func_00332FB0(D_0037CB60);
    return !D_00453B00.m24;
}

extern "C" int func_002DB820()
{
    int r = func_0031FE48(D_0037CB30);
    if (r < 0)
        func_00332FB0(D_0037CB40, D_0037CB30, r);
    while (NotBound_002DB820()) {
        for (int i = 0xFFFF; i != -1; i--) {
        }
    }
    D_00392EF0 = 1;
    return 1;
}
