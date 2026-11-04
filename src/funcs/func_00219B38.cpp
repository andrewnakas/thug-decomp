struct Params_00219B38;

extern char D_0038F720[];
extern char D_0038F550[];
extern char D_0038F558[];

extern "C" bool func_001E84E8(void* params, const char* name, unsigned int* out, int required);
extern "C" bool func_001E81F0(void* params, const char* name, void** out, int required);
extern "C" void* func_001190D0(unsigned int size);
extern "C" Params_00219B38* func_001E6978(void* mem);
extern "C" void func_001E6AC8(Params_00219B38* p, void* src);
extern "C" void* func_001E5548(unsigned int name, int a);
extern "C" void func_001E78A8(void* s, unsigned int name, Params_00219B38* p);

bool func_00219B38(void* params)
{
    unsigned int target;
    unsigned int name;
    void* src;
    func_001E84E8(params, D_0038F720, &target, 1);
    func_001E84E8(params, D_0038F550, &name, 1);
    func_001E81F0(params, D_0038F558, &src, 1);
    Params_00219B38* p = func_001E6978(func_001190D0(8));
    func_001E6AC8(p, src);
    func_001E78A8(func_001E5548(target, 1), name, p);
    return true;
}
