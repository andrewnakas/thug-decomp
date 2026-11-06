struct Slot_0021F860 {
    int m0;
    int m4;
    int m8;
};

struct Mgr_0021F860 {
    char m_pad0[0x94];
    Slot_0021F860 m94[64];
};

extern Mgr_0021F860* D_0038FC78;

bool Cmd_0021F860(void* params, void* script)
{
    for (int i = 63; i >= 0; i--)
        D_0038FC78->m94[i].m0 = 0;
    return true;
}
