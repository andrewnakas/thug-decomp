struct Ent_001365E8 {
    char pad0[0x20];
    unsigned int m_id;
    char pad24[0x30 - 0x24];
};

extern int D_00389E38;
extern Ent_001365E8 D_003BEC90[];

extern "C" Ent_001365E8* func_001365E8(unsigned int id)
{
    for (int i = 0; i < D_00389E38; i++) {
        Ent_001365E8* e = &D_003BEC90[i];
        if (e->m_id == id) {
            return e;
        }
    }
    return 0;
}
