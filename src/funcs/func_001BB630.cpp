extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);

struct Mgr_001BB630 {
    int m_pad[273];
    int m444[8];
};

extern Mgr_001BB630* D_0038FC78;

struct C_001BB630 {
    int m_pad[4];
    void Pick(void* params);
};

extern "C" void func_001BBA98(C_001BB630* self, int idx);

void C_001BB630::Pick(void* params)
{
    int v;
    if (func_001E7DE8(params, 0x67E6859A, &v, 0)) {
        func_001BBA98(this, D_0038FC78->m444[v]);
    } else if (func_001E7DE8(params, 0xB30D9965, &v, 0)) {
        func_001BBA98(this, v);
    }
}
