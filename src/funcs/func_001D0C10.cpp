/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Bucket_001D0BE8 {
    int m0;
    int m4;
    int m8;
    Bucket_001D0BE8();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table_001D0C10 {
    int m_bits;
    Bucket_001D0BE8* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table_001D0C10(int bits);
};

Table_001D0C10::Table_001D0C10(int bits)
{
    m_bits = bits;
    m_buckets = new Bucket_001D0BE8[1 << bits];
    m8 = 0;
    m14 = 0;
}
