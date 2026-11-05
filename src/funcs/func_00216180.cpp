struct G_00216180 {
    char m_pad[0x3BC];
    void* m3BC;
};
extern G_00216180* D_0038FC78;
extern "C" int func_001E8398(void* params, unsigned int name, int* out, int req);
extern "C" void func_0024FDF8(void* a, int v);

extern "C" int func_00216180(void* params)
{
    int v = 0;
    func_001E8398(params, 0, &v, 0);
    func_0024FDF8(D_0038FC78->m3BC, v);
    return 1;
}
