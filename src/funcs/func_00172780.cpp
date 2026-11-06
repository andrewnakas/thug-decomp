struct Entry_00172780 {
    char pad0[0x44];
    int m44;
    int m48;
    char pad4C[0x50 - 0x4C];
};

struct Model_00172780 {
    char pad0[0x30];
    int m30;
    int m34;
    Entry_00172780* m38;
};

struct Obj_00172780 {
    char pad0[0x64];
    void** m64;
    char pad68[0x70 - 0x68];
    Model_00172780* m70;
    void Fn(int a, int b, void* v);
};

void Obj_00172780::Fn(int a, int b, void* v)
{
    Entry_00172780* e = m70->m38;
    for (int i = 0; i < m70->m30; i++, e++) {
        if (e->m48 == a && e->m44 == b)
            m64[i] = v;
    }
}
