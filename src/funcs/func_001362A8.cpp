struct Ent_001362A8 {
    char m[0x30];
};

extern int D_00389E3C;
extern Ent_001362A8 D_003C1C90[];
extern "C" void func_00136F10(Ent_001362A8* e);

extern "C" void func_001362A8()
{
    for (int i = 0; i < D_00389E3C; i++) {
        func_00136F10(&D_003C1C90[i]);
    }
    D_00389E3C = 0;
}
