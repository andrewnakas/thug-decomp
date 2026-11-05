struct G_00216D38 {
    char m_pad[0x3B0];
    int m3B0;
};
extern G_00216D38* D_0038FC78;
extern "C" int func_001E8A30(void* params, unsigned int name, int* out, int req);

extern "C" bool func_00216D38(void* params)
{
    G_00216D38* g = D_0038FC78;
    int v;
    func_001E8A30(params, 0, &v, 1);
    return g->m3B0 == v;
}
