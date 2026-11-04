extern char D_0037C660[];

struct Mgr_002D8848 {
    int m0;
    void* m4;
    int m8;
    void* mC;
};

extern Mgr_002D8848* D_00392068;
extern "C" int func_001E54B8(char* s, int v);
extern "C" int func_002D30A8(void* p);
extern "C" void func_002D8248(void* p, int a, int b, int c);

extern "C" int func_002D8848()
{
    Mgr_002D8848* m = D_00392068;
    int n = func_001E54B8(D_0037C660, 0);
    func_002D8248(m->mC, 4, n, func_002D30A8(m->m4));
    return 1;
}
