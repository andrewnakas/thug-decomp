extern char D_00390870[];
extern char D_00375250[];
extern "C" int func_001E84E8(void* params, char* name, char** out, int req);
extern "C" void func_00103F28(char* s);

extern "C" int func_00254DA8(void* params)
{
    char* v;
    func_001E84E8(params, D_00390870, &v, 0);
    func_00103F28(D_00375250);
    return 1;
}
