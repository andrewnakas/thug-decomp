struct Entry_001727F8 {
    char pad0[0x44];
    int m44;
    int m48;
    char pad4C[0x50 - 0x4C];
};

struct Model_001727F8 {
    char pad0[0x30];
    int m30;
    int m34;
    Entry_001727F8* m38;
};

struct Obj_001727F8 {
    char pad0[0x64];
    unsigned int* m64;
    char pad68[0x70 - 0x68];
    Model_001727F8* m70;
    unsigned int Fn(int a, int b);
};

unsigned int Obj_001727F8::Fn(int a, int b)
{
    Entry_001727F8* e = m70->m38;
    for (int i = 0; i < m70->m30; i++, e++) {
        if (e->m48 == a && e->m44 == b)
            return m64[i];
    }
    return 0x80808080;
}
