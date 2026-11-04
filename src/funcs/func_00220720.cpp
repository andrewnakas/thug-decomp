extern void* D_0038FC78;
extern char D_0038F860[];
extern "C" void* func_0022E050(void* p);
extern "C" int func_001E87B8(void* params, const char* name);
extern "C" int func_00262828(void* g);
extern "C" void* func_00262860(void* g, int i);
extern "C" int func_00261F10(void* p, int a);
extern "C" void* func_0022E368(void* p, int i);

bool func_00220720(void* params, void* script)
{
    void* g = func_0022E050(D_0038FC78);
    if (func_001E87B8(params, D_0038F860)) {
        int n = func_00262828(g);
        for (int i = 0; i < n; i++) {
            func_00261F10(func_00262860(g, i), 1);
        }
    } else {
        func_00261F10(func_0022E368(D_0038FC78, 0), 1);
    }
    return true;
}
