/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj144438 {
    int m0;
    int m4;
    int m8;
    Obj144438();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table144460 {
    int m_bits;
    Obj144438* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table144460(int bits);
};

Table144460::Table144460(int bits)
{
    m_bits = bits;
    m_buckets = new Obj144438[1 << bits];
    m8 = 0;
    m14 = 0;
}
