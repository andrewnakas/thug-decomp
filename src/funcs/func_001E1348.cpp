struct Ent_001E1348 {
    int m0;
    char pad[0x100C];
};
extern Ent_001E1348 D_003ED8D0[];
extern "C" int func_001E1268(Ent_001E1348* e, void* p);

Ent_001E1348* func_001E1348(void* p)
{
    for (int i = 0; i < 1; i++) {
        if (!D_003ED8D0[i].m0) {
            if (func_001E1268(&D_003ED8D0[i], p))
                return &D_003ED8D0[i];
            return 0;
        }
    }
    return 0;
}
