/* cflags: -fno-schedule-insns */
struct Mgr_0021EA20 {
    char pad[0x3A0];
    void* m3A0;
};
extern Mgr_0021EA20* D_0038FC78;
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" void func_0025F838(void* p, unsigned int id);

extern "C" void func_0021EA20(void* params)
{
    unsigned int id = 0;
    func_001E8398(params, 0xA1DC81F9, &id, 0);
    func_0025F838(D_0038FC78->m3A0, id);
}
