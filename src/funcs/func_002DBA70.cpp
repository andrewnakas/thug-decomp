struct Req_002DBA70 {
    int m0;
    int m4;
    char m8[0x100];
    char m108[0x20];
};

extern int D_00392EF0;
extern Req_002DBA70 D_00453B40;
extern char D_00453B00[];
extern char D_00392EF8[];
extern char D_0037CB88[];
extern char D_0037CBF0[];
extern char D_0037CD28[];
extern "C" int func_00332FB0(const char* fmt, ...);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_0031DD70(void* a, int b, int c, void* d, int e, void* f, int g, int h, int i);

int Call_002DBA70(char* name, char* name2, int v)
{
    Req_002DBA70* r = &D_00453B40;
    if (!D_00392EF0) {
        func_00332FB0(D_0037CB88);
        return -1;
    }
    func_00331A9C(r->m8, name);
    func_00331A9C(r->m108, name2);
    r->m4 = v;
    func_0031DD70(D_00453B00, 2, 0, r, 0x128, r, 0x128, 0, 0);
    func_00332FB0(D_00392EF8, D_0037CBF0);
    func_00332FB0(D_0037CD28, D_00453B40.m0);
    return D_00453B40.m0;
}
