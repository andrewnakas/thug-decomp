struct Mgr_0021F618 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F618* D_0038FC78;
extern char D_0038F878[];
extern char D_0038F868[];
extern "C" bool func_001E88F8(void* params, const char* name, void** out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" bool func_00263D40(void* p, void* a, int b);

extern "C" bool func_0021F618(void* params, void* script)
{
    void* a;
    func_001E88F8(params, D_0038F878, &a, 1);
    int b = 0;
    func_001E7E58(params, D_0038F868, &b, 0);
    void* m = D_0038FC78->m24;
    if (b)
        return func_00263D40(m, a, b);
    return func_00263D40(m, a, -1);
}
