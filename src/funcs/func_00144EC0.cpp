/* sym: __13Hash_00144EC0i = 0x001451A8 */
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern void* D_00388A70;

struct Hash_00144EC0 {
    int m_bits;
    void* m_buckets;
    int m8;
    int mC;
    int m10;
    int m14;
    Hash_00144EC0(int bits);
    static void* operator new(unsigned int size) { return func_0010A638(D_00388A70, size, 1, 0); }
};

struct Obj_00144EC0 {
    Hash_00144EC0* m0;
    int m4;
    Obj_00144EC0();
};

Obj_00144EC0::Obj_00144EC0()
{
    m0 = new Hash_00144EC0(8);
    m4 = 1;
}
