struct Entry_001E0ED8 {
    char pad[0xC80];
    int mC80;
    char pad2[0xCB0 - 0xC84];
};

extern Entry_001E0ED8 D_003F0898[];
extern "C" int func_001DED20(int i);

extern "C" int func_001E0ED8(int i)
{
    if (func_001DED20(i))
        return 0;
    Entry_001E0ED8* e = &D_003F0898[i];
    return e->mC80;
}
