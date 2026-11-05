struct Ent_00112128 {
    int m0;
    int m_id;
    int m8;
    int mC;
    int m10;
};

extern Ent_00112128 D_00464DD0[64];
extern int D_00388E74;

static inline int Prev_00112128(int i)
{
    return i < 1 ? 63 : i - 1;
}

extern "C" Ent_00112128* func_00112128(int id)
{
    int i = Prev_00112128(D_00388E74);
    Ent_00112128* start = &D_00464DD0[i];
    Ent_00112128* e = start;
    do {
        if (e->m_id == id) {
            return e;
        }
        i = Prev_00112128(i);
        e = &D_00464DD0[i];
    } while (e != start);
    return 0;
}
