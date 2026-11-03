/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Bucket_002666C0 {
    int m0;
    int m4;
    int m8;
    Bucket_002666C0();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table_002666E8 {
    int m_bits;
    Bucket_002666C0* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table_002666E8(int bits);
};

Table_002666E8::Table_002666E8(int bits)
{
    m_bits = bits;
    m_buckets = new Bucket_002666C0[1 << bits];
    m8 = 0;
    m14 = 0;
}
