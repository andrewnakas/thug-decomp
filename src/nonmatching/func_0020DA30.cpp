/* fuzzy: 49.5 */
struct Flags_0020DA30 {
    char pad0[5];
    unsigned char m5;
    unsigned char m6;
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    unsigned char mB;
    unsigned char mC;
    unsigned char mD;
    unsigned char mE;
    unsigned char mF;
    unsigned char m10;
    char pad11[6];
    unsigned char m17;
    unsigned char m18;
    unsigned char m19;
};

struct Obj_0020DA30 {
    char pad[0x1C];
    Flags_0020DA30* m1C;
};

extern unsigned int D_003F5790[];
extern "C" int func_00183348(unsigned int name);
extern "C" unsigned int func_0010FC30();

bool Get_0020DA30(Obj_0020DA30* o, unsigned int name)
{
    if (!o)
        return false;
    if (!o->m1C)
        return false;
    unsigned int* t = &D_003F5790[func_00183348(name)];
    if (func_0010FC30() < *t)
        return false;
    switch (name) {
    case 0xBC6B118F:
        return o->m1C->m7;
    case 0xE3006FC4:
        return o->m1C->m8;
    case 0x85981897:
        return o->m1C->m6;
    case 0x4B358AEB:
        return o->m1C->m5;
    case 0xB7231A95:
        return o->m1C->m7 && o->m1C->m6;
    case 0xA50950C5:
        return o->m1C->m7 && o->m1C->m5;
    case 0xD8847EFA:
        return o->m1C->m8 && o->m1C->m6;
    case 0x786B8B68:
        return o->m1C->m8 && o->m1C->m5;
    case 0x2B489A86:
        return o->m1C->mA;
    case 0x321C9756:
        return o->m1C->mC;
    case 0x7323E97C:
        return o->m1C->mB;
    case 0x20689278:
        return o->m1C->m9;
    case 0x26B0C991:
        return o->m1C->mD;
    case 0xBFB9982B:
        return o->m1C->mF;
    case 0xF2F1F64E:
        return o->m1C->mE;
    case 0x6BF8A7F4:
        return o->m1C->m10;
    case 0x767A45D7:
        return o->m1C->m17;
    case 0xBD30325B:
        return o->m1C->m18;
    case 0x9D2D8850:
        return o->m1C->m19;
    }
    return false;
}
