struct Mgr_0021E9B0 {
    char pad[0x3A0];
    void* m3A0;
};
extern Mgr_0021E9B0* D_0038FC78;
extern char D_00371738[];
extern "C" bool func_001E8398(void* params, unsigned int name, int* out, int required);
extern "C" bool func_001E7E58(void* params, const char* name, int* out, int required);
extern "C" void func_0025F7A0(void* p, int a, bool b);

extern "C" bool func_0021E9B0(void* params, void* script)
{
    int a = 0;
    func_001E8398(params, 0xA1DC81F9, &a, 0);
    int b = 0;
    func_001E7E58(params, D_00371738, &b, 0);
    func_0025F7A0(D_0038FC78->m3A0, a, b != 0);
    return true;
}
