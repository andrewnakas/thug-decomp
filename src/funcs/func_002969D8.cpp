struct Ent_002969D8 {
    unsigned int m0;
    char pad4[0x114 - 0x4];
    unsigned int m114;
    char pad118[0x2A5 - 0x118];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

struct Mgr_002969D8 {
    char pad[0x20];
    Ent_002969D8 m20[50];
    void SetAll(int v);
};

extern "C" void func_00293928(Ent_002969D8* e, unsigned char v);

void Mgr_002969D8::SetAll(int v)
{
    for (int i = 0; i < 50; i++) {
        Ent_002969D8* e = &m20[i];
        if (e->m2A5 && e->m0 == 0xE8B4B836 && e->m114 == 0x61C5D092)
            func_00293928(e, v);
    }
}
