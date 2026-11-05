/* cflags: -fno-schedule-insns */
struct Mgr_0021F768 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F768* D_0038FC78;
extern "C" int func_001E88D8(void* params, unsigned int name, int* out, int req);
extern "C" void func_00263C78(void* p, int v);

static inline void Get_0021F768(void* params, int* out, unsigned int name)
{
    func_001E88D8(params, name, out, 1);
}

extern "C" void func_0021F768(void* params)
{
    int v;
    Get_0021F768(params, &v, 0x2E0B1465);
    func_00263C78(D_0038FC78->m24, v);
}
