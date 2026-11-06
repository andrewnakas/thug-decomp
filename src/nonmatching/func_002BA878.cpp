/* fuzzy: 40.0 */
struct Slot_002BA878 {
    int m0;
    int m4;
    char pad8[0x28];
};

struct Obj_002BA878 {
    char pad[0xCC];
    Slot_002BA878 mCC[18];
};

extern "C" void func_002BA878(Obj_002BA878* o)
{
    for (int i = 0; i < 18; i++) {
        if (o->mCC[i].m4)
            o->mCC[i].m0 = 0;
    }
}
