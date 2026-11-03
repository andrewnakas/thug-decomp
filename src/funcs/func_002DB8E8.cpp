struct Req_002DB8E8 {
    int m0;
    int m4;
    char m8[0x100];
};

extern int D_00392EF0;
extern Req_002DB8E8 D_00453B40;
extern char D_00453B00[];
extern char D_00392EF8[];
extern char D_0037CB88[];
extern char D_0037CBF0[];
extern char D_0037CC40[];
extern "C" int func_00332FB0(const char* fmt, ...);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_0031DD70(void* a, int b, int c, void* d, int e, void* f, int g, int h, int i);

int Call_002DB8E8(char* name, int v)
{
    Req_002DB8E8* r = &D_00453B40;
    if (!D_00392EF0) {
        func_00332FB0(D_0037CB88);
        return -1;
    }
    func_00331A9C(r->m8, name);
    r->m4 = v;
    func_0031DD70(D_00453B00, 1, 0, r, 0x108, r, 0x108, 0, 0);
    func_00332FB0(D_00392EF8, D_0037CBF0);
    func_00332FB0(D_0037CC40, D_00453B40.m0);
    return D_00453B40.m0;
}
