struct Params_002A9630 {
    char pad0[0x18];
    void* m18;
};

extern void* D_0038FC78;
extern char D_00378290[];
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F590(void* p);
extern "C" void func_001E7268(void* p, char* key, int v);

extern "C" bool func_002A9630(void* unused, Params_002A9630* s)
{
    int v = func_0024F590(func_0022E358(D_0038FC78));
    func_001E7268(s->m18, D_00378290, v);
    return true;
}
