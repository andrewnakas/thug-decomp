struct Mgr_0020DD58 {
    char pad0[0x28];
    int m28[2];
};

extern Mgr_0020DD58* D_00390828;
extern "C" int func_001E8398(void* p, unsigned int id, unsigned int* v, int f);
extern "C" int func_001E7DE8(void* p, unsigned int id, int* v, int f);
extern "C" int func_0020DA30(int a, unsigned int name);

bool func_0020DD58(void* params, void* script)
{
    Mgr_0020DD58* m = D_00390828;
    unsigned int name = 0;
    int idx;
    if (func_001E8398(params, 0, &name, 0)) {
        if (func_001E7DE8(params, 0, &idx, 0)) return func_0020DA30(m->m28[idx], name) != 0;
        for (int i = 0; i < 2; i++) {
            if (func_0020DA30(m->m28[i], name)) return true;
        }
        return false;
    }
    return false;
}
