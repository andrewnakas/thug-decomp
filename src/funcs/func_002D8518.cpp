struct Obj_002D8518 {
    char pad0[0xC];
    void* mC;
};

extern Obj_002D8518* D_00392068;
extern char D_00392D98[];
extern char D_00392DA0[];

extern "C" void func_001E7E58(void* p, char* name, int* out, int v);
extern "C" void func_001E7D18(void* p, char* name, char** out, int v);
extern "C" void func_002D7950(void* p, char* s, int v);

int func_002D8518(void* params)
{
    int v;
    char* s;
    Obj_002D8518* m = D_00392068;
    func_001E7E58(params, D_00392D98, &v, 1);
    func_001E7D18(params, D_00392DA0, &s, 1);
    func_002D7950(m->mC, s, v);
    return 1;
}
