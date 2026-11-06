struct Ent_00136D58 {
    char pad0[0x18];
    unsigned int m_id;
    char pad1C[0x30 - 0x1C];
};

extern int D_00389E3C;
extern Ent_00136D58 D_003C1C90[];

extern "C" Ent_00136D58* func_00136D58(unsigned int id)
{
    for (int i = 0; i < D_00389E3C; i++) {
        Ent_00136D58* e = &D_003C1C90[i];
        if (e->m_id == id) {
            return e;
        }
    }
    return 0;
}
