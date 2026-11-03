/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj18A9F0 {
    int m0;
    int m4;
    int m8;
    Obj18A9F0();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table18AB90 {
    int m_bits;
    Obj18A9F0* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table18AB90(int bits);
};

Table18AB90::Table18AB90(int bits)
{
    m_bits = bits;
    m_buckets = new Obj18A9F0[1 << bits];
    m8 = 0;
    m14 = 0;
}
