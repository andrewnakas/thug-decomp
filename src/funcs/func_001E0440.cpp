struct Ent_001E0440 {
    char pad[0xC98];
    long mC98;
    long mCA0;
    char pad2[8];
};
extern int D_0038E130;
extern int D_0038E13C;
extern Ent_001E0440 D_003F0898[];
extern "C" int func_001DED20();

void func_001E0440(void* p)
{
    if (func_001DED20())
        return;
    D_0038E13C = p != 0;
    Ent_001E0440* e = &D_003F0898[D_0038E130];
    e->mC98 = 0;
    e->mCA0 = 0;
}
