/* cflags: -fno-schedule-insns */
struct Mgr_0021F520 {
    char pad[0x24];
    void* m24;
};
extern Mgr_0021F520* D_0038FC78;
extern char D_0038F870[];
extern "C" bool func_001E88F8(void* params, char* name, int* out, int required);
extern "C" void func_00263A40(void* p, int v);

extern "C" void func_0021F520(void* params)
{
    int v;
    func_001E88F8(params, D_0038F870, &v, 1);
    func_00263A40(D_0038FC78->m24, v);
}
