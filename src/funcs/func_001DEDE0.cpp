struct Voice_001DEDE0 {
    int m0;
    int m4;
    char pad8[8];
    int m10;
    char pad14[0x14];
};

extern Voice_001DEDE0 D_003EE8E0[3];
extern "C" int func_001E3C58(int h);

extern "C" int func_001DEDE0(int id)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (D_003EE8E0[i].m4 == id && func_001E3C58(D_003EE8E0[i].m10) != 1) return i;
    }
    for (i = 0; i < 3; i++) {
        if (D_003EE8E0[i].m0 == id && func_001E3C58(D_003EE8E0[i].m10) != 1) return i;
    }
    return -1;
}
