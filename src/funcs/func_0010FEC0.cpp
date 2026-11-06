struct Ent_0010FEC0 {
    int m0;
    unsigned int m_size;
};

extern int D_0038881C;
extern int D_00388E18;
extern void* D_00388E24;
extern "C" Ent_0010FEC0* func_00112618(unsigned int key, void* tab);

extern "C" unsigned int func_0010FEC0(unsigned int key)
{
    if (!D_0038881C || !D_00388E18) {
        return 0;
    }
    if (!D_00388E24) {
        return 0;
    }
    Ent_0010FEC0* e = func_00112618(key, D_00388E24);
    if (e) {
        return e->m_size & 0x7FFFFFFF;
    }
    return 0;
}
