extern "C" unsigned int func_0010FC30();
extern "C" unsigned int func_00203300(unsigned int name, int a);
extern "C" float func_002032A0(unsigned int name, int a);

struct Entry_001AFC58 {
    unsigned int m0;
    int m4;
    char pad8[0xC];
    unsigned int m14;
};

struct Obj_001AFC58 {
    char pad[0x3C];
    Entry_001AFC58 m3C[100];
    unsigned short m99C;
    unsigned short m99E;
    float Method();
};

float Obj_001AFC58::Method()
{
    unsigned int window = func_00203300(0x6C83FDBF, 0);
    int count = 0;
    int idx = m99E;
    for (int i = 0; i < m99C; i++) {
        unsigned int t = m3C[idx].m0;
        if (func_0010FC30() - t >= window)
            break;
        if ((unsigned int)(m3C[idx].m4 - 1) < 2) {
            count++;
            m3C[idx].m14 = 0xFFFFFFFF;
        }
        idx--;
        if (idx < 0)
            idx += 100;
    }
    float r = count * func_002032A0(0xCED14273, 0);
    float cap = func_002032A0(0xD24ABFA3, 0) * 0.01f;
    if (cap < r)
        r = cap;
    return r + 1.0f;
}
