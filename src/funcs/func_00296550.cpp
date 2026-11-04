struct Ent_00296550 {
    unsigned int m0;
    char pad4[0x2A5 - 0x4];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

extern "C" void func_00292630(Ent_00296550* e);

struct Mgr_00296550 {
    char pad[0x20];
    Ent_00296550 m20[50];
    Ent_00296550* mA5C0;
    void Clear();
};

void Mgr_00296550::Clear()
{
    for (unsigned int i = 0; i < 50; i++) {
        Ent_00296550* e = &m20[i];
        if (e->m2A5 && e->m0 != 0xE8B4B836) func_00292630(e);
    }
    mA5C0 = 0;
}
