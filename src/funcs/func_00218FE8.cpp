struct Mgr_00218FE8 {
    char pad[0x3BC];
    void* m3BC;
};
extern Mgr_00218FE8* D_0038FC78;
extern "C" int func_001E8398(void* params, unsigned int id, int* out, int req);
extern "C" int func_001E8180(void* params, unsigned int id, int* out, int req);
extern "C" void func_0024FE20(void* p, int a, int b);

bool func_00218FE8(void* params, void* script)
{
    int a = 0;
    int b = 0;
    func_001E8398(params, 0, &a, 0);
    func_001E8180(params, 0x7031F10C, &b, 0);
    func_0024FE20(D_0038FC78->m3BC, a, b);
    return true;
}
