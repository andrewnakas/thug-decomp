struct Mgr_0021F338 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F338* D_0038FC78;
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" int func_00263930(void* p);

extern "C" bool func_0021F338(void* params, void* script)
{
    int v;
    func_001E88D8(params, 0, &v, 1);
    return func_00263930(D_0038FC78->m24) == v;
}
