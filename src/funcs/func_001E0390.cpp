struct Entry_001E0390 {
    char m_pad0[0xC80];
    int mC80;
    long mC88;
    long mC90;
    long mC98;
    long mCA0;
    int mCA8;
    char m_padCAC[0xCB0 - 0xCAC];
};

extern Entry_001E0390 D_003F0898[];
extern int D_0038E14C;
extern "C" int func_001DED20();

extern "C" void func_001E0390(int i)
{
    if (func_001DED20())
        return;
    D_0038E14C = 0;
    Entry_001E0390* e = &D_003F0898[i];
    e->mCA0 = 0;
    e->mC80 = 0;
    e->mC88 = 0;
    e->mC90 = 0;
    e->mC98 = 0;
    e->mCA8 = 1;
}
