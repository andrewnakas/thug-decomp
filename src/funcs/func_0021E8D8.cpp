struct Mgr_0021E8D8 {
    char pad[0x3A0];
    void* m3A0;
};
extern Mgr_0021E8D8* D_0038FC78;
extern char D_0038F850[];
extern "C" int func_001E87B8(void* params, void* name);
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" void func_0025F9D0(void* p, int v, void* params, unsigned int id);

bool func_0021E8D8(void* params, void* script)
{
    func_001E87B8(params, D_0038F850);
    int v = 0;
    func_001E8398(params, 0xA1DC81F9, &v, 0);
    func_0025F9D0(D_0038FC78->m3A0, v, params, 0x12743EDB);
    return true;
}
