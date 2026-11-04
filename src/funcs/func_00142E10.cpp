/* cflags: -fopt-stack */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Obj142DD8 {
    int m0;
    int m4;
    int m8;
    Obj142DD8();
    static void* operator new[](unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Table142E10 {
    int m_bits;
    Obj142DD8* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Table142E10(int bits);
};

Table142E10::Table142E10(int bits)
{
    m_bits = bits;
    m_buckets = new Obj142DD8[1 << bits];
    m8 = 0;
    m14 = 0;
}
