extern char D_0038F8E0[];
extern char D_0038F908[];
extern char D_00371A10[];
extern char D_003718C0[];
extern int D_0038FC78;

extern "C" void func_001E84E8(void* params, char* name, unsigned int* out, int required);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" void func_001E81F0(void* params, char* name, void** out, int required);
extern "C" bool func_001E8398(void* params, unsigned int key, int* out, int required);
extern "C" void* func_0022E050(int a);
extern "C" int func_001E87B8(void* params, char* name);
extern "C" void* func_00262990(void* a);
extern "C" int func_00262388(void* a);
extern "C" int func_00262828(void* a);
extern "C" void* func_00262860(void* a, int i);
extern "C" void func_001E7E58(void* params, char* name, int* out, int required);

bool func_002227C8(void* params)
{
    unsigned int name;
    func_001E84E8(params, D_0038F8E0, &name, 1);
    void* s = func_001E5548(name, 1);
    if (!s)
        return false;
    void* p;
    func_001E81F0(s, D_0038F908, &p, 1);
    if (!p)
        return false;
    int v;
    if (!func_001E8398(p, 0x5B8AB877, &v, 0))
        return false;
    void* t = func_0022E050(D_0038FC78);
    if (func_001E87B8(p, D_00371A10))
        return func_00262388(func_00262990(t)) != v;
    int n = func_00262828(t);
    for (int i = 0; i < n; i++) {
        void* o = func_00262860(t, i);
        if (func_00262388(o) == v) {
            int h = 0;
            func_001E7E58((char*)o + 0x5C, D_003718C0, &h, 0);
            return h != 0;
        }
    }
    return false;
}
