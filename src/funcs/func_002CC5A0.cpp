struct Item_002CC5A0 {
    char pad0[0x1C];
    char m1C[0x9C - 0x1C];
    char m9C[0xC0 - 0x9C];
    char mC0[0x20];
};

extern "C" char* func_00331A9C(char* d, const char* s);

struct Obj_002CC5A0 {
    int m0;
    Item_002CC5A0* m4[32];
    int m84[32];
    char* Get(int i, int* out);
};

char* Obj_002CC5A0::Get(int i, int* out)
{
    if (m4[i]) {
        *out = m84[i] == 0;
        func_00331A9C(m4[i]->mC0, m4[i]->m1C);
        return m4[i]->m9C;
    }
    return 0;
}
