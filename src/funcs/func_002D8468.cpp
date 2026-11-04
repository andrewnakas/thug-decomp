struct Obj_002D8468 {
    char pad0[0xC];
    void* mC;
};

extern Obj_002D8468* D_00392068;
extern char D_0037C5F8[];
extern char D_0037C3F0[];
extern char D_0037C3E0[];

extern "C" int func_001E87B8(void* p, char* name);
extern "C" void func_002D7638(void* p, int a, int b, int c);

int func_002D8468(void* params)
{
    Obj_002D8468* m = D_00392068;
    int a = func_001E87B8(params, D_0037C5F8);
    int b = func_001E87B8(params, D_0037C3F0);
    func_002D7638(m->mC, a, b, func_001E87B8(params, D_0037C3E0));
    return 1;
}
