/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj1349C8 {
    int m0;
    int m4;
    int m8;
    Obj1349C8();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table1349F0 {
    int m_bits;
    Obj1349C8* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table1349F0(int bits);
};

Table1349F0::Table1349F0(int bits)
{
    m_bits = bits;
    m_buckets = new Obj1349C8[1 << bits];
    m8 = 0;
    m14 = 0;
}
