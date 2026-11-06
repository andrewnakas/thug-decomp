extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Wave_001471E8;
extern "C" Wave_001471E8* func_0017DC68(void* mem, int a, int b, int c, int d, int id);
extern "C" short func_0017ECA8(Wave_001471E8* w);
extern "C" short func_0017ECB0(Wave_001471E8* w);
extern "C" unsigned char func_0017EDC8(Wave_001471E8* w);
extern "C" unsigned char func_0017EE30(Wave_001471E8* w);
extern "C" unsigned char func_0017EE88(Wave_001471E8* w);
extern "C" int func_0017EE90(Wave_001471E8* w);

struct Snd_001471E8 {
    char pad[0xC];
    short mC;
    short mE;
    unsigned char m10;
    unsigned char m11;
    unsigned char m12;
    int m14;
    int m18;
    Wave_001471E8* m1C;
    bool Load(int a, int b, int c, int d);
};

bool Snd_001471E8::Load(int a, int b, int c, int d)
{
    m1C = func_0017DC68(func_0010A638(D_00388A70, 0x58, 1, 0), a, b, c, d, m18);
    if (m1C) {
        mC = func_0017ECA8(m1C);
        mE = func_0017ECB0(m1C);
        m10 = func_0017EDC8(m1C);
        m11 = func_0017EE30(m1C);
        m12 = func_0017EE88(m1C);
        m14 = func_0017EE90(m1C);
    }
    return m1C != 0;
}
