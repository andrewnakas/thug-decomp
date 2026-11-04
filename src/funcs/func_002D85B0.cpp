extern char D_00392D98[];

struct Mgr_002D85B0 {
    char pad[0xC];
    void* mC;
};

extern Mgr_002D85B0* D_00392068;
extern "C" int func_001E7E58(void* params, char* name, int* out, int req);
extern "C" void func_002D7AE0(void* p, int v);

extern "C" int func_002D85B0(void* params)
{
    Mgr_002D85B0* m = D_00392068;
    int v;
    func_001E7E58(params, D_00392D98, &v, 1);
    func_002D7AE0(m->mC, v);
    return 1;
}
