/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj142928 {
    int m0;
    int m4;
    int m8;
    Obj142928();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table142950 {
    int m_bits;
    Obj142928* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table142950(int bits);
};

Table142950::Table142950(int bits)
{
    m_bits = bits;
    m_buckets = new Obj142928[1 << bits];
    m8 = 0;
    m14 = 0;
}
