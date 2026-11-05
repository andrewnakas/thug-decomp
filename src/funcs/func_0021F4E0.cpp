struct G_0021F4E0 {
    char m_pad[0x24];
    void* m24;
};
extern G_0021F4E0* D_0038FC78;
extern char D_0038F870[];
extern "C" int func_001E88F8(void* params, char* name, int* out, int req);
extern "C" bool func_00263A00(void* a, int bit, int idx);

extern "C" bool func_0021F4E0(void* params)
{
    int v;
    func_001E88F8(params, D_0038F870, &v, 1);
    return func_00263A00(D_0038FC78->m24, v, -1);
}
