struct Ent_001E13D8 {
    int m0;
    char pad[0x100C];
};
extern Ent_001E13D8 D_003ED8D0[];
extern "C" int func_001E1318(Ent_001E13D8* e, int id);

int func_001E13D8(int id)
{
    for (int i = 0; i < 1; i++) {
        if (D_003ED8D0[i].m0 == id)
            return func_001E1318(&D_003ED8D0[i], id);
    }
    return 0;
}
