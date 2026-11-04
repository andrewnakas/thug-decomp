struct Ent_002967E0 {
    unsigned int m0;
    char pad4[0x114 - 0x4];
    unsigned int m114;
    char pad118[0x2A5 - 0x118];
    unsigned char m2A5;
    char pad2A6[0x350 - 0x2A6];
};

struct Mgr_002967E0 {
    char pad[0x20];
    Ent_002967E0 m20[50];
    bool Hit(float a, float b, float c, float d);
};

extern "C" int func_002951A0(Ent_002967E0* e, float a, float b, float c, float d);

bool Mgr_002967E0::Hit(float a, float b, float c, float d)
{
    for (int i = 0; i < 50; i++) {
        Ent_002967E0* e = &m20[i];
        if (e->m2A5 && e->m0 == 0xE8B4B836 && func_002951A0(e, a, b, c, d))
            return true;
    }
    return false;
}
